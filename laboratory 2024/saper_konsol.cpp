/*
The task was to write a minesweeper game using recursion
The icons are taken from unicode
*/

#include <iostream>
#include <clocale>
#include <vector>
#include <algorithm>
#include <fcntl.h>
#include <conio.h>

using namespace std;

struct id_nomer{
    int kord_y;
    int kord_x;
};

void bomb_polie(int& count_bomb, int& dlina_polia){
    cout << "Введите кол-во бомб и длину: ";
    cin >> count_bomb >> dlina_polia;
    while ((count_bomb > (dlina_polia*dlina_polia-1)) || (dlina_polia > 99)){
        cout << endl << "Вы что-то ввели не правильно попробуйте ещё раз\nКол-во бомб и длина: ";
        cin >> count_bomb >> dlina_polia;
    }
}

void prov_kord(int& koord_y, int& koord_x, int dlina_polia){
    while (koord_x > dlina_polia || koord_y > dlina_polia || koord_y == 0 || koord_x == 0){
        wcout << endl << "Вы что-то ввели не правильно попробуйте ещё раз\nY X: ";
        cin >> koord_y >> koord_x;
    }
}

vector<id_nomer> rand_bomb(int count_bomb, int dlina_polia){
    vector<id_nomer> nomers; //храним айди бомб;
    int n, n_2, fl = 1;
    for (int i = 0; i < count_bomb; i++) {
        n = rand()%dlina_polia + 1;
        n_2 = rand()%dlina_polia + 1;
        while (fl == 1) {
            for (auto & nomer : nomers) {
                while (nomer.kord_y == n and nomer.kord_x == n_2) {
                    n = rand()%dlina_polia + 1;
                    n_2 = rand()%dlina_polia + 1;
                    fl = 3;
                }
            }
            if (fl == 3)
                fl = 1;
            else
                fl = 2;
        }
        fl = 1;
        nomers.emplace_back();
        nomers[i].kord_y = n;
        nomers[i].kord_x = n_2;
    }
    return nomers;
}

vector<vector<wchar_t>> zap_matrix(vector<vector<wchar_t>> matrix, int dlina_polia){
    for (int i = 0; i<dlina_polia; i++){
        vector <wchar_t> vr;
        for (int j = 0; j < dlina_polia; j++){
            vr.push_back(0x25A0);
        }
        matrix.push_back(vr);
        vr.clear();
    }
    return matrix;
}

void vivod_polia(vector<vector<wchar_t>> matrix, int dlina_polia){
    _setmode(_fileno(stdout), _O_U16TEXT);
    system("cls");
    wcout << endl;
    for (int i = -1; i<dlina_polia; i++){
        wcout << " " << i+1 << "  ";
        if (i < 9 and dlina_polia > 9)
            wcout << " ";
        for (int j = 0; j < dlina_polia; j++){
            if (i == -1)
                wcout << j+1 << " ";
            else {
                wcout << matrix[i][j] << " ";
                if (j > 7 and dlina_polia > 8)
                    wcout << " ";
            }
        }
        if (i == -1)
            wcout << endl;
        wcout << endl;
    }
}

int podshet_bomb_vokrug(vector<id_nomer> nomers, int id_i, int id_j, int dlina_polia){
    int counts = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if ((!(i == 0 and j == 0)) && ((id_i+i) > 0 and (id_i+i) < (dlina_polia+1) and (id_j+j) > 0 and (id_j+j) < (dlina_polia+1))) {
                for (auto &nomer: nomers) {
                    if (nomer.kord_y == (id_i + i) and nomer.kord_x == (id_j + j))
                        counts++;
                }
            }
        }
    }
    return counts;
}

void ochihenie(vector<vector<wchar_t>>& matrix, vector<id_nomer> nomers, int id_i, int id_j, int dlina_polia,  vector<wchar_t> ar_cifr){
    // Проверяем границы доски
    if (id_i < 1 or id_i > dlina_polia or id_j < 1 or id_j > dlina_polia){
        return;
    }

    for (auto & nomer : nomers) {
        if ((nomer.kord_y == id_i) and (nomer.kord_x == id_j)) {
            return;
        }
    }

    if (matrix[id_i-1][id_j-1] == (wchar_t)0x25A0){
        int counts = 0;
        counts = podshet_bomb_vokrug(nomers, id_i, id_j, dlina_polia);
        matrix[id_i-1][id_j-1] = ar_cifr[counts];
        if (counts == 0){
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (!(i == 0 and j == 0))
                        ochihenie(matrix, nomers, id_i+i, id_j+j, dlina_polia, ar_cifr);
                }
            }
        }
    }
    else
        return;
}

int prov_win(vector<vector<wchar_t>> matrix, int dlina_polia, int count_bomb) {
    int counts = 0;
    for (int i = 0; i < dlina_polia; i++) {
        for (int j = 0; j < dlina_polia; j++)
            if (matrix[i][j] == (wchar_t)0x25A0 || matrix[i][j] == (wchar_t)0x2732)
                counts++;
    }
    if (counts == count_bomb)
        return 2;
    return 1;

}

int prov_bomb(vector<vector<wchar_t>>& matrix, vector<id_nomer> nomers, int id_i, int id_j, int dlina_polia, int game, int count_bomb, vector<wchar_t> ar_cifr, char key){
    int counts = 0;
    if (key == '1' && matrix[id_i - 1][id_j - 1] == (wchar_t)0x25A0){
        matrix[id_i - 1][id_j - 1] = (wchar_t)0x2732;
        vivod_polia(matrix, dlina_polia);
        game = prov_win(matrix, dlina_polia, count_bomb);
        return game;
    }
    else if (key == '1' && matrix[id_i - 1][id_j - 1] == (wchar_t)0x2732){
        matrix[id_i - 1][id_j - 1] = (wchar_t)0x25A0;
        vivod_polia(matrix, dlina_polia);
        game = prov_win(matrix, dlina_polia, count_bomb);
        return game;
    }
    for (auto & nomer : nomers){
        if (nomer.kord_y == id_i and nomer.kord_x == id_j) {
            matrix[id_i - 1][id_j - 1] = (wchar_t) 0x25CF;
            game = 0;
            vivod_polia(matrix, dlina_polia);
            return game;
        }
    }
    if (key == '2') {
        counts = podshet_bomb_vokrug(nomers, id_i, id_j, dlina_polia);
        if (counts == 0 && matrix[id_i-1][id_j-1] != (wchar_t)0x2732){
            ochihenie(matrix, nomers, id_i, id_j, dlina_polia, ar_cifr);
        }
        else
            matrix[id_i - 1][id_j - 1] = ar_cifr[counts];
        vivod_polia(matrix, dlina_polia);
        game = prov_win(matrix, dlina_polia, count_bomb);
        return game;
    }
    else{
        wcout << endl << "Вы ошиблись" << endl;
        vivod_polia(matrix, dlina_polia);
        game = prov_win(matrix, dlina_polia, count_bomb);
        return game;
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    srand ( time(NULL) );
    int count_bomb, dlina_polia, game = 1, koord_y, koord_x;
    char key = ' ';
    vector <wchar_t> ar_cifr = {0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038};
    vector<vector <wchar_t>> matrix;
    vector<id_nomer> nomers;
    bomb_polie(count_bomb, dlina_polia); // enter the number of bombs and the length
    matrix = zap_matrix(matrix, dlina_polia); // filling the matrix with cells
    nomers = rand_bomb(count_bomb, dlina_polia); // Loading bombs
    vivod_polia(matrix, dlina_polia);  // field output
    while(game == 1){
        wcout << endl << "1 - поставить/убрать флаг\n"
                         "2 - открыть ячейку";
        key = getch();
        wcout << endl << endl << "Введите координаты Y X:";
        cin >> koord_y >> koord_x;
        prov_kord(koord_y, koord_x, dlina_polia);
        game = prov_bomb(matrix, nomers, koord_y, koord_x, dlina_polia, game, count_bomb, ar_cifr, key);
    }
    if (game == 0)
        wcout << endl << "GAME OVER" << endl;
    else
        wcout << endl << "WIN" << endl;
    return 0;
}
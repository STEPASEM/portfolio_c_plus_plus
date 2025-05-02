#include "lab3.h"

template<typename IDType>
Library_Cards<IDType>::Library_Cards(IDType id, string name_lib, string name_author,
        string date_of_issue, string date_of_return) :
        id(id), name_lib(name_lib), name_author(name_author),
        date_of_issue(date_of_issue), date_of_return(date_of_return){};

template<typename IDType>
void Library_Cards<IDType>::return_book(IDType id_) {
    if (id_ == id) {
        cout << "Book was returned" << endl;
        cout << "Book name: " << name_lib << endl;
        cout << "Return date: " << date_of_return << endl << endl;
    }
}

template<typename IDType>
bool Library_Cards<IDType>::operator==(Library_Cards<IDType>& obj) {
    return name_author == obj.name_author;
}

template<typename IDType>
Book<IDType>::Book(IDType id_, string name_lib_, string name_author_,
        string date_of_issue_, string date_of_return_, string genre_, string parametr_):
        Library_Cards<IDType>(id_, name_lib_, name_author_, date_of_issue_, date_of_return_), genre(genre_), parametr(parametr_){};

template<typename IDType>
bool Book<IDType>::operator==(Book<IDType>& obj) {
    if ((genre == obj.genre) && (genre == "’удожественный")){
        return 1;
    }
    return 0;
}

template<typename IDType>
void Book<IDType>::return_book_gen(IDType id_){
    if (id_ == this->id){
        cout << "Book was returned" << endl;
        cout << "Book genre: " << genre << endl;
        cout << "Return parametr: " << parametr << endl << endl;
    }
}
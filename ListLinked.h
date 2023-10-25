#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>

class ListLinked : public List<T>{
  
 private:
  
  Node<T>* first;
  int n;
  
 public:

  ListLinked(){

    n = 0;
    first = nullptr;
    
  }


  ~ListLinked(){

    while( first != nullptr){
      Node<T> aux = first -> next;
      delete first;
      first = aux;
    }
  }

  T operator[](int pos){


    if( pos < 0 || pos > n)
      throw std:: out_of_range("Esta posicion esta fuera del rango");

    else{

      Node<T>* aux = first;
      for( int i = 0; i < pos; i++){
	aux = aux -> next;
      }

      return aux -> data;

    }

  }

  friend std:: ostream&operator<<(std::ostream &out, const ListLinked<T> &list){
    
    out<< "List :[";

    Node <T>* aux = list.first;

    while(aux){
      out<< aux->data;
      if(aux->next != nullptr)
	out<<",";

      aux = aux->next;

  }
    out<<"]";
    return out;
}

  virtual void insert(int pos, T e){

    if(pos > n || pos < 0)
      throw std:: out_of_range("La posición esta fuera del rango");


    if(pos == 0)
    prepend(e);

    else if(pos == n)
      append(e);

    else{
      Node <T>* aux = first;

      for(int i = 1; i < pos; i++){

	aux = aux -> next;
      }
      Node<T>* aux2 = new Node<T>(e, aux->next);
      aux -> next = aux;
      n++;
     
    }
  }



  virtual void append(T e) override {

    if(first == nullptr)
      prepend(e);

    else{

      Node<T>* aux = first;
      for(int i = 1; i < size()-1; i++){
      aux = aux->next;
      }

      Node<T>* aux2 = new Node<T>(e, aux -> next);

      aux -> next = aux2;
    }
      
    n++;


  }

  virtual void prepend(T e) override {

    Node<T>* aux = new Node<T>(e, first);
    first = aux;
    n++;
      

  }

  virtual T remove(int pos) override {

    Node <T>* aux = first;
    Node <T>* borrar;
    int elim;

    if(pos < 0 || pos > size() -1)
      throw std::out_of_range("La posición está fuera del rango");

    else{
    
    for(int i = 1; i < pos; i++){
      
      aux = aux -> next;
      
    }
    
    borrar = aux -> next;
    elim = borrar -> data;
    aux -> next = borrar -> next;
    }

    n--;
    delete borrar;
    return elim;

    
    
  }

  virtual T get(int pos) override {
    
    if(pos > size()-1 || pos < 0)
      throw std:: out_of_range("La posición está fuera adel rango");
    
    else{
      
      Node <T>* aux = first;
      
      for(int i = 1; i < pos; i++){
	
      aux = aux -> next;
    }
    
    return aux->data;
    }
  }
  
  virtual int search(T e) {
    int i;
    Node <T>* aux = first;
    for(i = 0; i < n; i++){
      if(aux ->data == e)
	return i;
      
      else
	aux = aux -> next;
    }
    return -1;
      }
  
  virtual bool empty()override {
    
    if(n == 0)
      return true;
    else
      return false;
    
  }

  virtual int size() override{

    return n;

  }
};

  

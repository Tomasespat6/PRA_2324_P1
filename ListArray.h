#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
	
	T *arr;
	int max;
	int n;
	static const int MINSIZE = 2;


  void resize(int new_size){
  
    T arr2 [new_size];
    for(int i = 0; i < new_size; i++)
      arr2[i] = arr[i];
	  
    delete arr;
    
    arr = new int[new_size];
    for(int i = 0; i < new_size; i++)
      arr[i] = arr2[i];

	
	max = new_size;

	  
    
  }
  
  
public:
  
ListArray(){
    arr = new int [MINSIZE];
   max = 2;
    n = 0;
   

  }

  ~ ListArray(){

    delete[] arr;

  }

  T operator [](int pos ) {


          if (pos < 0 || pos > n)
            throw std::out_of_range("No se puede introducir en esta posicion");

          else
            return arr[pos];
  }

  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    out<<"List -> [ ";
    for(int i = 0; i < list.n ; i++){
      out<< list.arr[i]<<" ";

    }
    out<<"]";
    return out;
  }
  
  virtual void insert(int pos, T e) override {
    int i;
    
	if(pos < 0 || pos > n)
      throw std::out_of_range("No se puede introducir en esta posicion");

    if (size() == max)
      resize(size()*2);
    
    if (pos == 0)
      prepend(e);
    
    else if(pos == n)
      append(e);
    
    else
      for(i = n; i > pos; i--){	
	arr[i]= arr[i-1];
      }
    
    arr[pos]= e;
    n++;
    
  }
  
  virtual void append( T e) override {
    
    if(size() == max)
      resize(size()*2);
    
    arr[n] = e;
    n++;
  }
  
  virtual void prepend(T e) override {
    int i;
    
    if(size() == max)
      resize(size()*2);
    
    else{
    for(i = n; i > 0; i--)
      arr[i]= arr[i-1];
    
    
    arr[0]= e;
    n++;
   
    } 
  }
  
  
  virtual T remove(int pos) override{

	  T c = arr[pos];

	if(pos < 0 || pos > size()-1)
      	throw std::out_of_range("No se puede introducir en esta posicion");

	else{
    for(int i = pos; i < size(); i++)
      arr[i]= arr[i+1];
    
    n--;
    return c;
	}
    
  }
  virtual T get (int pos) override {
    
    T c = arr[pos];
    
    if(pos < 0 || pos > size()-1)
      throw std::out_of_range("No se puede introducir en esta posicion");
    else
    return c;
  }
  
		
  
  virtual int search(T e) override {
    for(int i = 0; i < n; i++) {
      if(arr[i]== e) 
	return i;
    }
    
      return -1;
    
  }
  
  virtual bool empty() override {
    if(n == 0)
      return true;
    else
      return false;
  }
  virtual int size() override{ 
    return n;
  }
  

};

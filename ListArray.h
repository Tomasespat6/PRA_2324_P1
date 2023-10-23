#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
	
	T *arr;
	int max;
	int n;
	static constint INT MINSIZE = 2;

	public:


  virtual void insert(int pos, T e) override {
    int i;

    if (size() == MAX)
      resize(size()*2);
    
    if (pos == 0)
      prepend(e);
    
    else if(pos == n)
      append(e);
    
    else
      for(i = n; i > pos; i--)	
	arr[i]= arr[i-1];
     
    
    arr[pos]= e;
    n++;
    
    if(pos < 0 || pos > n)
      throw out_of_range("No se puede introducir en esta posicion");
  }
  
  virtual void append( T e) override {

    if(size() == MAX)
      resize(size()*2);
    
    arr[n] = e;
    n++;
	}
  
  virtual void prepend(T e) override {
    int i;

    if(size() == MAX)
      resize(size()*2);
    
    for(i = n; i > 0; i--){
	    arr[i]= arr[i-1];
    }
    arr[pos]= e;
    n++;
    
    if(pos < 0 || pos > size()-1)
      throw out_of_range("No se puede introducir en esta posicion");
  }
  
	
  virtual T remove(int pos) override{
    T c = arr[pos];
    for(i = pos; i < size(); i++)
      arr[i]= arr[i+1];
    
    n--;
    return c;
    
    if(pos < 0 || pos > size()-1)
      throw out_of_range("No se puede introducir en esta posicion");
    
  }
  virtual T get (int pos) override {
    
    T c = arr[pos];
    
    if(pos < 0 || pos > size()-1)
      throw out_of_range("No se puede introducir en esta posicion");
    
    return c;
  }
  
		
  
  virtual int search(T e) override {
    for(i = 0; i < n; i++) {
      if(arr[i]== e) 
	return i;
    }
    else
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

#endif

  ListArray(){
	  arr = new int [MINSIZE];
	  n = 0;
	  MINSIZE = 2;
	  MAX = 2;
	  
	}

~ ListArray(){
	  
	  delete arr;
	
	}

T operator [](int pos ) {
	  
	  m = search(T e);
	if (m == -1)
	  throw out_of_range("No se puede introducir en esta posicion");
	
	else
	  return m;
	}

friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
   out<<"List -> [ ";
   for(int i = 0; i < list.n ; i++){
     out<< list.arr[i]<<" ";
     
   }
   out<<"]";
   return out;
 }

void resize(int new_size) override{
  
 	T arr2 [new_size];
	for(int i = 0; i < new_size; i++)
         arr2[i] = arr[i];
	  
	  delete arr;

	  arr = new int[new_size];
	  for(int i = 0; i < new_size; i++)
	    arr[i] = arr2[i]
	      max = new_size;

	  
     
	}
};

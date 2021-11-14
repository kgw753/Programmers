#include "OrderedList.h"
using namespace std;

OrderedList::OrderedList(){
    itemCount = 0;
    size = DEFAULTSIZE;
    items = new int[size];
}

OrderedList::~OrderedList(){
    delete [] items;
}

int OrderedList::getItem(int index){
    if(index > -1 && index < size){
        return items[index];
    }
    else{
        return -99999;
    }
}

void OrderedList::addItem(int itm){
    if(itemCount >= size){
        int * newItems = new int[size * 2];
        for(int i = 0; i < size; i++){
            newItems[i] = items[i];
        }
        size *= 2;
        delete [] items;
        items = newItems;
    }
    int pos;
    for(pos = 0; pos < itemCount; pos++){
        if(items[pos] >= itm){
            break;
        }
    }
    this->insertItem(pos, itm);
}

void OrderedList::insertItem(int index, int itm){
    if(index < 0 || index > itemCount){
        cout<<"index error"<<endl;
        return;
    }

    if(itemCount >= size){
        int * newItems = new int[size * 2];
        for(int i = 0; i < size; i++){
            newItems[i] = items[i];
        }
        size *= 2;
        delete [] items;
        items = newItems;
    }

    for(int i = itemCount; i > index; i--){
        items[i] = items[i - 1];
    }
    itemCount++;
    items[index] = itm;
}

int OrderedList::removeAt(int index){
    if(index < 0 || index >= itemCount){
        return -99999;
    }

    int removed = items[index];
    for(int i = index; i < itemCount; i++){
        items[i] = items[i + 1];
    }
    itemCount--;
    return removed;
}

int OrderedList::removeItem(int itm){
    int removed;
    bool found = false;
    int index;
    for(index = 0; index < itemCount; index++){
        if(itm == items[index]){
            removed = items[index];
            found = true;
            break;
        }
    }

    if(found){
        for(int i = index; i < itemCount; i++){
            items[i] = items[i + 1];
        }
        itemCount--;
        return removed;
    }
    else{
        return -99999;
    }
}

OrderedList OrderedList::operator+(OrderedList &list){
    OrderedList addedList;
    
    for(int i = 0; i < this->itemCount; i++){
        addedList.addItem(this->getItem(i));
    }

    for(int i = 0; i < list.itemCount; i++){
        addedList.addItem(list.getItem(i));
    }

    return addedList;
}

void OrderedList::print(){
    cout << "======================" << endl;
    for(int i = 0; i < itemCount; i++){
        cout<< "idx " << i << " : " << items[i] << endl;
    }
    cout << "======================" << endl;
}
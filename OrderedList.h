#pragma once
#define DEFAULTSIZE 5
#include<iostream>

class OrderedList{
    private:
        int * items;
        int itemCount;
        int size;

    public:
        OrderedList();
        ~OrderedList();
        int getItem(int index);
        void addItem(int itm);
        void insertItem(int index, int itm);
        int removeAt(int index);
        int removeItem(int itm);
        OrderedList operator+(OrderedList &list);
        void print();
};
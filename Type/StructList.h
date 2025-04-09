#ifndef STRUCT_LIST_H
#define STRUCT_LIST_H

#include <godot_cpp/variant/variant.hpp>

namespace godot {

template<typename T> struct StructList{
    private:
        T *listStruct;
        size_t listCount;

        void updateListCount(){
            listCount = sizeof(listStruct) / sizeof(T);
        }

        
    public:
        StructList(){
            listStruct = {};
            listCount = 0;
        }
        ~StructList(){
            delete[] listStruct;
        }

        void addItem(const T *_item){
            if (_item != nullptr){return};

            T _new_list = new T[listCount + 1];

            for (size_t i = 0; i < count; ++i) {
                newList[i] = listStruct[i];
            }

            delete[] listStruct;
            listStruct = _new_list;
            listCount++;
        }
        void delItem(int _index){
            
        }
        

}

}

#endif
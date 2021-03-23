
#include "table2.h"

namespace main_savitch_12B
{
    template <class RecordType>
    table<RecordType>::table()
    {
        total_records = 0;
    }
    
    template <class RecordType>
    table<RecordType>::table(const table& source)
    {
        total_records = source.total_records;
        for (int i=0; i<TABLE_SIZE; i++) {
            data[i] = source.data[i];
        }
    }
    
    template <class RecordType>
    table<RecordType>::~table()
    {
        delete[] data;
        total_records = 0;
    }
    
    template <class RecordType>
    void table<RecordType>::insert(const RecordType& entry)
    {
        std::size_t i = hash(entry.key);
        if(!is_present(entry.key)){
            data[i].push_back(entry);
            total_records = total_records + 1;
        }
        else{
            remove(entry.key);
            data[i].push_back(entry);
        }
    }
    
    template <class RecordType>
    void table<RecordType>::remove(int key)
    {
        std::size_t i = hash(key);
        if(!is_present(key))
            return;
        else{
            typename std::list<RecordType>::iterator iter;
            for(iter = data[i].begin(); iter != data[i].end(); iter++){
                if(iter->key == key){
                    data[i].erase(iter);
                    total_records = total_records-1;
                    break;
                }
            }
        }
    }
    
    template <class RecordType>
    void table<RecordType>::operator =(const table& source)
    {
        for (int i=0; i<TABLE_SIZE; i++) {
            list_clear(data[i]);
        }
        total_records = source.total_records;
        for (int i=0; i<TABLE_SIZE; i++) {
            data[i] = source.data[i];
        }
    }
    
    template <class RecordType>
    void table<RecordType>::find(int key, bool& found, RecordType& result) const
    {
        std::size_t i = hash(key);
        if(is_present(key)){
            found = true;
            typename std::list<RecordType>::const_iterator iter;
            for(iter = data[i].begin(); iter != data[i].end(); iter++){
                if(iter->key == key)
                    result = *iter;
                return;
            }
        }
        else
            found = false;
    }
    
    template <class RecordType>
    bool table<RecordType>::is_present(int key) const
    {
        std::size_t i = hash(key);
        typename std::list<RecordType>::const_iterator iter;
        for(iter = data[i].begin(); iter != data[i].end(); iter++){
            if(iter->key == key)
                return true;
        }
        return false;
    }
    
    template <class RecordType>
    std::size_t table<RecordType>::hash(int key) const
    {
        int hash = (key % TABLE_SIZE);
        return hash;
    }
}

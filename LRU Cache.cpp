#include <unordered_map>
#include <list>

class LRUCache{
private: 
    int capacity;
    int num;
    
    unordered_map<int, list< pair<int,int> >::iterator > ht;
    list< pair<int,int> > cache;
    typedef list< pair<int,int> >::iterator lstItr;

public:
    LRUCache(int cap) {
        capacity = cap;
        num = 0;
        cache.resize(0);
        ht.clear();
    }

    void moveToFront( lstItr itor ){
        if( itor != cache.begin() ){
            cache.splice( cache.begin(), cache, itor );
        }
    }

    void moveToEnd( lstItr itor ){
        if( itor != cache.end() ){
            cache.splice( cache.end(), cache, itor );
        }
    }
    
    int get(int key) {
        if( ht.find(key) != ht.end() ){
            auto itor = ht[key];
            cache.splice( cache.begin(), cache, itor) ;
            return cache.front().second;
        }
        else{
            return -1;
        }
    }
    
    void set(int key, int value) {
        if( ht.find(key) != ht.end() ){
            auto itor = ht[key];
            cache.splice( cache.begin(), cache, itor) ;
            cache.front().second = value;
        }
        else{
            if( num == capacity ){
                //delete oldest
                ht.erase( cache.back().first );
                cache.back() = pair<int, int>(key, value);
                //then insert too
                moveToFront( --cache.end() );
                //cache.pop_back();
                //cache.push_front( pair<int, int>(key, value) );
                ht[key] = cache.begin();
            }
            else{
                num++;
                cache.push_front( pair<int, int>(key, value) );
                ht[key] = cache.begin();
            }
        }
    }
};

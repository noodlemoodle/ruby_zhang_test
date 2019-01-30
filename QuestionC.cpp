#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

void sampleCache();

struct page {
  int pageNumber;
  string pageValue;
};

// lru cache 
class LruCache {
  
  private:
    int cacheSize;
    list<int> lruQueue; // in order of lru to mru 
    unordered_map<int, struct page> cacheMap; // page# & addr
    void setCacheSize(int size) { cacheSize = size; }
    int getCacheSize() { return cacheSize; }

  public : 

    LruCache(int size) {
      setCacheSize(size);
    }

    // return pagevalue 
    string retrievePage(int pageNumber) {
      if(cacheMap.find(pageNumber) == cacheMap.end()) {
        // page is not in cacheMap 
        cout << "page " << pageNumber << " not found - retrieving from other source and adding to cache" << endl<< endl;

        // this is the "retrieved page" 
        struct page p; 
        p.pageNumber = pageNumber;
        p.pageValue = "new page";

        if(lruQueue.size() == getCacheSize()) {
          // if cache is full, delete the least recently used.
          cacheMap.erase(lruQueue.front());
          lruQueue.pop_front();
        } 
        // add new page as most recently used
        cacheMap.insert(make_pair(pageNumber, p));
        lruQueue.push_back(pageNumber);
        return p.pageValue;
        
      } else {
        cout << "page " << pageNumber << " found in cache"<< endl<< endl;
        // page is in cacheMap 
        // move the retrieved page to the end of queue as most recently used 
        // find page number in lruQueue
        for(auto page : lruQueue) {
          if(page == pageNumber) {
            // remove this entry and push it to the back of 
            // the queue as most recently used 
            lruQueue.remove(pageNumber);
            lruQueue.push_back(pageNumber);
            break;
          }
        }
        return cacheMap[pageNumber].pageValue;

      }
    }

    void displayCache() {
      cout << "Current cache contents ..." << endl;
      for(auto &page : lruQueue) {
        cout << page << " : " << cacheMap[page].pageValue << endl;
      }
      cout << endl;
    }

};

int main() {
  
  sampleCache();

  return 0;
}

void sampleCache() {
  LruCache c(5);
  for(int i = 0; i < 6; i++) {
    c.retrievePage(i);
    c.displayCache();
  }
}

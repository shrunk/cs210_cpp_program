#ifndef _itemcounter_h
#define _itemcounter_h

#include <map>
#include <string>

using namespace std;

/** ItemCounter handles counting the occurrences of a set of strings, encapsulating a map of item name to integer count. */
class ItemCounter {

public:
	ItemCounter() {}
	~ItemCounter() {}

	void add(const string& type) {
		counts[type] = get(type) + 1;
	}

	int get(const string& type) {
		map<string, int>::iterator it = counts.find(type);
		return it == counts.end() ? 0 : it->second;
	}

	map<string, int>::iterator iterate() {
		return counts.begin();
	}

	map<string, int>::iterator end() {
		return counts.end();
	}

private:
	// using the standard map maintains alphabetical iteration order
	map<string, int> counts;
};


#endif

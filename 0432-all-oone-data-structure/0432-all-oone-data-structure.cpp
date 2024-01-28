class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(dataMap.find(key) == dataMap.end()) { // we've got a new a key which doesn't exist in map
            if(dataList.size() && dataList.begin()->first == 1) { // we already've a list node with value as 1 so no need to create a new node
                dataList.begin()->second.insert(key); // insert key in the existing node
            } else { // no list node exist with value 1 so create a list node
                unordered_set<string> keysSet = { key };
                dataList.push_front({1, keysSet});
            }
            dataMap[key] = dataList.begin(); // update the key reference
            
        } else { // key already exist in the map 
            auto currentPos = dataMap[key];
            int incrementedValue = currentPos->first + 1;
            auto nextPos = next(currentPos, 1);
            currentPos->second.erase(key); // delete key from the currentPos as we have incremented its value

            if(currentPos->second.size() == 0) { // if that was the only key in the list node then remove that node also
                dataList.erase(currentPos);
            }
            if(nextPos != dataList.end() && incrementedValue == nextPos->first) { // key's new incremented value is already there in the list so just need to insert the key in the list node
                nextPos->second.insert(key);
                dataMap[key] = nextPos;
            } else { // need to create a new list node
                unordered_set<string> keysSet = { key };
                auto newPos = dataList.insert(nextPos, {incrementedValue, keysSet});
                dataMap[key] = newPos;
            }
        }
    }
    
    void dec(string key) {
        if(dataMap.find(key) != dataMap.end()) { // key exist in the map
            auto currentPos = dataMap[key];
            int decrementedValue = currentPos->first - 1;
            list<pair<int, unordered_set<string>>>::iterator prevPos;
            bool isStartOfList = true;
            if(currentPos != dataList.begin()) {
                prevPos = next(currentPos, -1);
                isStartOfList = false;
            }
            currentPos->second.erase(key); //delete key from the currentPos as we have decremented its value
            auto nextPos = next(currentPos, 1);
            bool isCurrentPosDeleted = false;
            if(currentPos->second.size() == 0) { // if that was the only key in the list node then remove that node also
                dataList.erase(currentPos);
                isCurrentPosDeleted = true;
            }
            if(decrementedValue == 0) { // if new key value is 0 then remove it from the map also
                dataMap.erase(key);
            } else if(!isStartOfList && prevPos->first == decrementedValue) { // decremented value already exist in list so only need to insert the key to the list node
                prevPos->second.insert(key);
                dataMap[key] = prevPos;
            } else { // need to create a new list node
                unordered_set<string> keysSet;
                keysSet.insert(key);
                list<pair<int, unordered_set<string>>>::iterator insertBeforeItr;
                if(isCurrentPosDeleted) {
                    insertBeforeItr = nextPos;
                } else {
                    insertBeforeItr = currentPos;
                }
                auto newPos = dataList.insert(insertBeforeItr, {decrementedValue, keysSet});
                dataMap[key] = newPos;
            }

        }
    }
    
    string getMaxKey() {
        if(dataList.size()) {
            return (*(dataList.rbegin()->second).begin()); // list end node
        }
        return "";
    }
    
    string getMinKey() {
        if(dataList.size()) {
            return (*(dataList.begin()->second).begin()); //list first node
        }
        return "";
    }
private:
    list<pair<int, unordered_set<string>>> dataList;
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> dataMap;
};
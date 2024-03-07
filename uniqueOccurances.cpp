class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occurrencesMap;
        for (const auto& i: arr) {
            occurrencesMap[i]++;
        }
        
        bool isUnique = true;
        unordered_set<int> uniqueCountsSet;

        for (const auto& entry: occurrencesMap) {
            if (!uniqueCountsSet.insert(entry.second).second) {
                isUnique = false;
                break;
            }
        }

        return isUnique;
    }
};

 def uniqueOccurrences(self, arr: List[int]) -> bool:
        # Create an empty dictionary to store the occurrences of each element
        d = {}
        
        # Iterate through the input array
        for i in arr:
            # If the element is not in the dictionary, add it with an initial count of 1
            if i not in d.keys():
                d[i] = 1
            # If the element is already in the dictionary, increment its count
            else:
                d[i] += 1

        # Check if the number of unique occurrences is the same as the total number of occurrences
        return len(list(set(d.values()))) == len(d.values())
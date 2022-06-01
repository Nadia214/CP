<<<<<<< HEAD
//706. Design HashMap
//Tc -0(1)
//sc- 0(n)
class MyHashMap {
public:
    vector<vector<int>> data;
    MyHashMap() {
        data.resize(1001, vector<int>());
    }
    void put(int key, int value) {
        int hKey = key % 1000;
        if (data[hKey].empty()) {
            data[hKey].resize(1001, -1);
        }
        data[hKey][key / 1000] = value;
    }
    int get(int key) {
        int hKey = key % 1000;
        if (!data[hKey].empty()) {
            return data[hKey][key / 1000];
        }
        return -1;
    }
    void remove(int key) {
        int hKey = key % 1000;
        if (!data[hKey].empty()) {
            data[hKey][key / 1000] = -1;
        }
    }
};
=======
//Tc -0(1)
//sc- 0(n)
class MyHashMap {
public:
    MyHashMap() {
        data.resize(1001, vector<int>());
    }
    void put(int key, int value) {
        int hashKey = key % 1000;
        if (data[hashKey].empty()) {
            data[hashKey].resize(1001, -1);
        }
        data[hashKey][key / 1000] = value;
    }
    int get(int key) {
        int hashKey = key % 1000;
        if (!data[hashKey].empty()) {
            return data[hashKey][key / 1000];
        }
        return -1;
    }
    void remove(int key) {
        int hashKey = key % 1000;
        if (!data[hashKey].empty()) {
            data[hashKey][key / 1000] = -1;
        }
    }

private:
    vector<vector<int>> data;
};
>>>>>>> 68fce0a1f9b9b34f5b12912a7a9770c9e632c20a

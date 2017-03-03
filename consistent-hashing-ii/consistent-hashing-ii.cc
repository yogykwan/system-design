class Solution {
    public:
    // @param n a positive integer
    // @param k a positive integer
    // @return a Solution object
    static Solution create(int n, int k) {
        // Write your code here
        srand(time(nullptr));
        Solution solution = Solution();
        solution.points.clear();
        solution.point_machine.clear();
        solution.n_machines = n;
        solution.n_points = k;
        return solution;
    }
    
    // @param machine_id an integer
    // @return a list of shard ids
    vector<int> addMachine(int machine_id) {
        // Write your code here
        vector<int> point_list;
        for (int i = 0; i < n_points; ++i) {
            while (true) {
                int tmp = rand() % n_machines;
                if (points.find(tmp) == points.end()) {
                    points.insert(tmp);
                    point_machine[tmp] = machine_id;
                    point_list.push_back(tmp);
                    break;
                }
            }
        }
        return point_list;
    }
    
    // @param hashcode an integer
    // @return a machine id
    int getMachineIdByHashCode(int hashcode) {
        // Write your code here
        set<int>::iterator it = points.lower_bound(hashcode);
        if (it == points.end()) {
            return point_machine[*points.lower_bound(0)];
        } else {
            return point_machine[*it];
        }
    }
    
    public:
    int n_machines;
    int n_points;
    set<int> points;
    map<int, int> point_machine;
};

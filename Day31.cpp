// 1146. Snapshot Array
// Implement a SnapshotArray that supports the following interface:

// SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
// void set(index, val) sets the element at the given index to be equal to val.
// int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
// int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

class SnapshotArray
{
public:
    vector<map<int, int>> A;
    int sid = 0;
    SnapshotArray(int length)
    {
        A.resize(length);

        for (int i = 0; i < length; i++)
        {
            A[i][0] = 0;
        }
    }

    void set(int index, int val)
    {
        A[index][sid] = val;
    }

    int snap()
    {
        sid++;
        return sid - 1;
    }

    int get(int index, int snap_id)
    {

        if (A[index].find(snap_id) == A[index].end())
        {
            auto it = --A[index].lower_bound(snap_id);
            return it->second;
        }
        return A[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
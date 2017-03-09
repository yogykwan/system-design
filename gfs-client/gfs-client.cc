/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */
class GFSClient : public BaseGFSClient {
public:
    GFSClient(int chunkSize) {
        // initialize your data structure here
        chunk_size = chunkSize;
        file_chunks.clear();
    }

    // @param filename a file name
    // @return conetent of the file given from GFS
    string read(string& filename) {
        // Write your code here
        string ans;
        if (file_chunks.find(filename) != file_chunks.end()) {
            int cnt = file_chunks[filename];
            for (int i = 0; i < cnt; ++i) {
                ans += readChunk(filename, i);
            }
        }
        return ans;
    }

    // @param filename a file name
    // @param content a string
    // @return void
    void write(string& filename, string& content) {
        // Write your code here
        int len = content.length(), i = 0;
        while (i < len / chunk_size) {
            string t = content.substr(i * chunk_size, chunk_size);
            writeChunk(filename, i, t);
            ++i;
        }
        if (len % chunk_size) {
            string t = content.substr(i * chunk_size, len % chunk_size);
            writeChunk(filename, i, t);
            ++i;
        }
        file_chunks[filename] = i;
    }

private:
    int chunk_size;
    map<string, int> file_chunks;
};


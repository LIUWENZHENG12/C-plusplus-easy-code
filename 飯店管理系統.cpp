// C++ 飯店管理系統範例程式
#include <algorithm> // 包含排序演算法 std::sort
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定義飯店資料類別
class Hotel {
public:
    string name;      // 飯店名稱
    int roomAvl;      // 剩餘空房數
    string location;  // 所在地點
    int rating;       // 評分
    int pricePr;      // 每間房價格
};

// 定義使用者資料類別，繼承自 Hotel
// (雖然這裡使用繼承，但在邏輯上比較像是 User 關聯到 Hotel 的資料)
class User : public Hotel {
public:
    string uname;     // 使用者姓名
    int uId;          // 使用者 ID
    int cost;         // 訂房花費總額
};

// 排序邏輯：按飯店名稱排序 (降冪)
bool sortByBan(Hotel& A, Hotel& B)
{
    return A.name > B.name;
}

// 排序邏輯：按飯店評分排序 (降冪)
bool sortByr(Hotel& A, Hotel& B)
{
    return A.rating > B.rating;
}

// 排序邏輯：按空房數排序 (升冪)
bool sortByRoomAvailable(Hotel& A, Hotel& B)
{
    return A.roomAvl < B.roomAvl;
}

// 列印所有飯店的原始資料
void PrintHotelData(vector<Hotel> hotels)
{
    cout << "--- 飯店資料列表 ---" << endl;
    cout << "飯店名稱  空房數  地點      評分  房價" << endl;

    for (int i = 0; i < 3; i++) {
        cout << hotels[i].name << "        "
             << hotels[i].roomAvl << "        "
             << hotels[i].location << "    "
             << hotels[i].rating << "      "
             << hotels[i].pricePr << endl;
    }
    cout << endl;
}

// 執行飯店名稱排序並列印結果
void SortHotelByName(vector<Hotel> hotels)
{
    cout << "--- 依名稱排序 (降冪) ---" << endl;

    // 使用 STL sort，帶入自定義的比較函數 sortByBan
    std::sort(hotels.begin(), hotels.end(), sortByBan);

    for (int i = 0; i < hotels.size(); i++) {
        cout << hotels[i].name << " " << hotels[i].roomAvl << " "
             << hotels[i].location << " " << hotels[i].rating << " "
             << hotels[i].pricePr << endl;
    }
    cout << endl;
}

// 執行評分排序並列印結果
void SortHotelByRating(vector<Hotel> hotels)
{
    cout << "--- 依評分排序 (降冪) ---" << endl;

    std::sort(hotels.begin(), hotels.end(), sortByr);

    for (int i = 0; i < hotels.size(); i++) {
        cout << hotels[i].name << " " << hotels[i].roomAvl << " "
             << hotels[i].location << " " << hotels[i].rating << " "
             << hotels[i].pricePr << endl;
    }
    cout << endl;
}

// 根據指定城市篩選飯店
void PrintHotelBycity(string s, vector<Hotel> hotels)
{
    cout << "位於 " << s << " 的飯店有:" << endl;
    for (int i = 0; i < hotels.size(); i++) {
        if (hotels[i].location == s) {
            cout << hotels[i].name << " " << hotels[i].roomAvl << " "
                 << hotels[i].location << " " << hotels[i].rating << " "
                 << hotels[i].pricePr << endl;
        }
    }
    cout << endl;
}

// 依據空房數排序並由多到少列印
void SortByRoomAvailable(vector<Hotel> hotels)
{
    cout << "--- 依空房數排序 (從多到少) ---" << endl;

    std::sort(hotels.begin(), hotels.end(), sortByRoomAvailable);

    // 這裡從 size-1 開始反向遍歷，達成從多到少的顯示效果
    for (int i = hotels.size() - 1; i >= 0; i--) {
        cout << hotels[i].name << " " << hotels[i].roomAvl << " "
             << hotels[i].location << " " << hotels[i].rating << " "
             << hotels[i].pricePr << endl;
    }
    cout << endl;
}

// 整理並列印使用者訂房資料
void PrintUserData(string userName[], int userId[], int bookingCost[], vector<Hotel> hotels)
{
    vector<User> user;
    User u;

    // 將陣列資料封裝進 User 物件向量中
    for (int i = 0; i < 3; i++) {
        u.uname = userName[i];
        u.uId = userId[i];
        u.cost = bookingCost[i];
        user.push_back(u);
    }

    cout << "--- 使用者訂房資料明細 ---" << endl;
    cout << "用戶名    用戶ID    飯店名    訂房費用" << endl;

    for (int i = 0; i < user.size(); i++) {
        cout << user[i].uname << "         "
             << user[i].uId << "         "
             << hotels[i].name << "         "
             << user[i].cost << endl;
    }
}

// 飯店管理系統核心處理函數
void HotelManagement(string userName[], int userId[], string hotelName[], 
                     int bookingCost[], int rooms[], string locations[], 
                     int ratings[], int prices[])
{
    vector<Hotel> hotels;
    Hotel h;

    // 資料初始化：建立飯店物件清單
    for (int i = 0; i < 3; i++) {
        h.name = hotelName[i];
        h.roomAvl = rooms[i];
        h.location = locations[i];
        h.rating = ratings[i];
        h.pricePr = prices[i];
        hotels.push_back(h);
    }
    cout << endl;

    // 執行各項功能展示
    PrintHotelData(hotels);
    SortHotelByName(hotels);
    SortHotelByRating(hotels);
    PrintHotelBycity("Bangalore", hotels);
    SortByRoomAvailable(hotels);
    PrintUserData(userName, userId, bookingCost, hotels);
}

// 主程式入口
int main()
{
    // 初始化測試資料
    string userName[] = { "U1", "U2", "U3" };
    int userId[] = { 2, 3, 4 };
    string hotelName[] = { "H1", "H2", "H3" };
    int bookingCost[] = { 1000, 1200, 1100 };
    int rooms[] = { 4, 5, 6 };
    string locations[] = { "Bangalore", "Bangalore", "Mumbai" };
    int ratings[] = { 5, 5, 3 };
    int prices[] = { 100, 200, 100 };

    // 啟動飯店管理邏輯
    HotelManagement(userName, userId, hotelName, bookingCost, 
                    rooms, locations, ratings, prices);

    return 0;
}

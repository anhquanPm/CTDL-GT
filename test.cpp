#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
using namespace std;

/*
    code by Tran Anh Quan dep trai so 2 khong ai so 1 🤡
*/

int slvlxd;

struct NhanVien
{
    string sMaNV, sTenNV;
};

struct VLXD
{
    string sTenHang, sMaHang;
    int iSoLuong, itongSoLuong = 0;
    float fDonGia;
    double dThanhTien;
};

struct KhachHang
{
    string sMaKH, sTenKH, sDiaChi, sDienThoai;
};

struct HoaDon
{
    string sNgayLap;
    int iSoHD;
    VLXD vlxd[10];
    KhachHang kh[20];
    NhanVien nv[10];
};

struct NodeHoaDon
{
    HoaDon data;
    struct NodeHoaDon *next;
    struct NodeHoaDon *prev;
};

struct ListNode
{
    NodeHoaDon *head;
    NodeHoaDon *tail;
};

void init(ListNode &l)
{
    l.head = NULL;
    l.tail = NULL;
}

NodeHoaDon *makeNode(HoaDon hd)
{
    NodeHoaDon *p = new NodeHoaDon;

    if (p == NULL)
    {
        cout << "\n KHONG DU BO NHO";
        exit(1);
    }
    p->data = hd;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void chenDau(ListNode &l, NodeHoaDon *new_val)
{
    if (l.head == NULL)
    {
        l.head = new_val;
        l.tail = l.head;
    }
    else
    {
        new_val->next = l.head; // con tro next cua p tro den dia chi cua node head (ban dau)
        l.head->prev = new_val; // con tro prev cua head ban dau tro den gia tri cua p
        l.head = new_val;
    }
}

void chenCuoi(ListNode &l, NodeHoaDon *new_val)
{

    if (l.head == NULL)
    {
        l.head = new_val;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = new_val;
        new_val->prev = l.tail;
        l.tail = new_val; // cap nhat lai l.tail
    }
}

void nhapThongTinVLXD(VLXD &v)
{
    cin.ignore(1);
    cout << "\n Nhap ten hang: ";
    getline(cin, v.sTenHang);
    cout << "\n Nhap ma hang: ";
    getline(cin, v.sMaHang);
    cout << "\n Nhap don gia: ";
    cin >> v.fDonGia;
    cout << "\n Nhap so luong: ";
    cin >> v.iSoLuong;
    v.dThanhTien = (1.0) * v.fDonGia * v.iSoLuong;
    v.itongSoLuong = v.itongSoLuong + v.iSoLuong;
}

void inThongTinVLXD(VLXD v)
{
    cout << setw(30) << left << v.sTenHang;
    cout << setw(10) << v.sMaHang;
    cout << setw(10) << v.fDonGia;
    cout << setw(10) << v.iSoLuong;
    cout << setw(15) << right << v.dThanhTien << endl;
}

int tongSoLuongVLXD(HoaDon hd)
{
    int tong = 0;
    for (int i = 0; i < slvlxd; i++)
    {
        tong = tong + hd.vlxd[i].itongSoLuong;
    }
    return tong;
}

double tongTienThanhToanCua1HoaDon(HoaDon hd)
{
    double tongTien = 0.0; // Initialize the total amount to zero

    for (int i = 0; i < slvlxd; i++)
    {
        tongTien = tongTien + hd.vlxd[i].dThanhTien;
    }

    return tongTien;
}

void nhapThongTinKhachHang(KhachHang &kh)
{
    cin.ignore();
    cout << "\n Nhap ma khach hang: ";
    getline(cin, kh.sMaKH);
    cout << "\n Nhap ten khach hang: ";
    getline(cin, kh.sTenKH);
    cout << "\n Nhap dia chi: ";
    getline(cin, kh.sDiaChi);
    cout << "\n Nhap so dien thoai: ";
    getline(cin, kh.sDienThoai);
}

void inThongTinKhachHang(KhachHang kh)
{
    cout << "\n Ma Khach hang: " << kh.sMaKH;
    cout << "\n Ten khach hang: " << kh.sTenKH;
    cout << "\n Dia chi: " << kh.sDiaChi;
    cout << "\n So dien thoai: " << kh.sDienThoai << endl;
}

void nhapThongTinNhanVien(NhanVien &nv)
{
    cin.ignore(1);
    cout << "\n Nhap ma nhan vien: ";
    getline(cin, nv.sMaNV);
    cout << "\n Nhap ten nhan vien lap hoa don: ";
    getline(cin, nv.sTenNV);
}

void inThongTinNhanVien(NhanVien nv)
{
    cout << "\n Ten nhan vien lap hoa don: " << nv.sTenNV << endl;
}

void nhapThongTinHoaDon(HoaDon &hd)
{
    cin.ignore(1);
    cout << "\n Ngay lap hoa don: ";
    getline(cin, hd.sNgayLap);
    cout << "\n So hoa don: ";
    cin >> hd.iSoHD;

    for (int i = 0; i < 1; i++)
    {
        nhapThongTinKhachHang(hd.kh[i]);
    }

    cout << "\n Nhap so luong vat lieu xay dung: ";
    cin >> slvlxd;

    for (int i = 0; i < slvlxd; i++)
    {
        nhapThongTinVLXD(hd.vlxd[i]);
    }

    for (int i = 0; i < 1; i++)
    {
        nhapThongTinNhanVien(hd.nv[i]);
    }
}

void inThongTinHoaDon(HoaDon hd)
{
    cout << "\n \t \t \t ----------------HOA DON MUA BAN VAT LIEU XAY DUNG----------------";
    cout << "\n Ngay lap hoa don: " << hd.sNgayLap;
    cout << "\n So hoa don: " << hd.iSoHD;

    // in thong tin khach hang
    for (int i = 0; i < 1; i++)
    {
        inThongTinKhachHang(hd.kh[i]);
    }

    // in thong tin vat lieu xay dung.
    cout << endl;
    cout << setw(30) << left << "TEN HANG";
    cout << setw(10) << "MA HANG";
    cout << setw(10) << "DON GIA";
    cout << setw(10) << "SO LUONG";
    cout << setw(15) << right << "THANH TIEN" << endl;
    for (int i = 0; i < slvlxd; i++)
    {
        inThongTinVLXD(hd.vlxd[i]);
    }
    cout << "\nTong so vat lieu xay dung da mua la: " << tongSoLuongVLXD(hd);
    cout << "\nTong tien can thanh toan cua hoa don la: " << tongTienThanhToanCua1HoaDon(hd) << " VNĐ";

    // in thong tin nhan vien lap hoa don
    for (int i = 0; i < 1; i++)
    {
        inThongTinNhanVien(hd.nv[i]);
    }
}

void nhapDSHoaDon(ListNode &l)
{
    NodeHoaDon *p;
    int m;
    cout << "\n Nhap so luong hoa don: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        HoaDon hd;
        nhapThongTinHoaDon(hd);
        p = makeNode(hd);
        chenCuoi(l, p);
    }
}

void inDSHoaDon(ListNode l)
{
    NodeHoaDon *p;
    for (p = l.head; p != NULL; p = p->next)
    {
        inThongTinHoaDon(p->data);
    }
}

// DOC GHI XOA FILE ------------------------------------------------------------------------------

void docFileHoaDon(ListNode &l)
{
    // mo file de doc
    ifstream file("hoaDon.txt", ios::in);

    if (!file.is_open())
    {
        cout << "Khong the mo file hoaDon.txt!" << endl;
        return;
    }

    // Read each line of the file
    string line;
    while (getline(file, line))
    {
        HoaDon hd;

        // doc tung dong
        stringstream ss(line);

        string token;
        getline(ss, token, ',');
        hd.sNgayLap = token;

        getline(ss, token, ',');
        hd.iSoHD = stoi(token);

        // doc khach hang
        for (int i = 0; i < 1; i++)
        {
            getline(ss, token, ',');
            hd.kh[i].sMaKH = token;

            getline(ss, token, ',');
            hd.kh[i].sTenKH = token;

            getline(ss, token, ',');
            hd.kh[i].sDiaChi = token;

            getline(ss, token, ',');
            hd.kh[i].sDienThoai = token;
        }

        // doc so luong vat lieu xay dung
        getline(ss, token, ',');
        slvlxd = stoi(token);

        // doc thong tin vat lieu xay dung
        for (int i = 0; i < slvlxd; i++)
        {
            getline(ss, token, ',');
            hd.vlxd[i].sTenHang = token;

            getline(ss, token, ',');
            hd.vlxd[i].sMaHang = token;

            getline(ss, token, ',');
            hd.vlxd[i].fDonGia = stof(token);

            getline(ss, token, ',');
            hd.vlxd[i].iSoLuong = stoi(token);

            // tinh tong so tien thanh toan
            hd.vlxd[i].dThanhTien = (1.0) * hd.vlxd[i].fDonGia * hd.vlxd[i].iSoLuong;
            hd.vlxd[i].itongSoLuong = hd.vlxd[i].itongSoLuong + hd.vlxd[i].iSoLuong;
        }

        // doc thong tin nhan vien
        for (int i = 0; i < 1; i++)
        {
            getline(ss, token, ',');
            hd.nv[i].sMaNV = token;

            getline(ss, token);
            hd.nv[i].sTenNV = token;
        }

        // them hoa don vao danh sach lien ket
        NodeHoaDon *p = makeNode(hd);
        chenCuoi(l, p);
    }

    // dong file
    file.close();
}

void ghiFileDSHoaDon(ListNode l)
{
    // mo file de ghi du lieu
    ofstream file("hoaDon.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Khong the ghi file hoaDon.txt!" << endl;
        return;
    }

    // viet tung hoa don vao file
    NodeHoaDon *p;
    for (p = l.head; p != NULL; p = p->next)
    {
        file << p->data.sNgayLap << "," << p->data.iSoHD << ",";

        // ghi du lieu khach hang
        for (int i = 0; i < 1; i++)
        {
            file << p->data.kh[i].sMaKH << "," << p->data.kh[i].sTenKH << ",";
            file << p->data.kh[i].sDiaChi << "," << p->data.kh[i].sDienThoai << ",";
        }

        // ghi du lieu so luong vlxd
        file << slvlxd << ",";

        // ghi thong tin vlxd
        for (int i = 0; i < slvlxd; i++)
        {
            file << p->data.vlxd[i].sTenHang << "," << p->data.vlxd[i].sMaHang << ",";
            file << p->data.vlxd[i].fDonGia << "," << p->data.vlxd[i].iSoLuong << ",";
        }

        // ghi thong tin nhan vien
        for (int i = 0; i < 1; i++)
        {
            file << p->data.nv[i].sMaNV << "," << p->data.nv[i].sTenNV << endl;
        }
    }
    // dong file
    file.close();
}

void xoaFile(string tenFile)
{
    // Kiểm tra xem file có tồn tại hay không
    ifstream file(tenFile.c_str(), ios::in);
    if (file.is_open())
    {
        // File tồn tại, xóa file
        file.close();
        remove(tenFile.c_str());
        cout << "Xóa file " << tenFile << " thành công!" << endl;
    }
    else
    {
        // File không tồn tại
        cout << "File " << tenFile << " không tồn tại!" << endl;
    }
}

void giaiPhongBoNho(ListNode &l)
{
    NodeHoaDon *p = l.head;
    NodeHoaDon *next;

    while (p != NULL)
    {
        next = p->next;
        delete p; // giải phóng bộ nhớ cho con trỏ p
        p = next;
    }

    // Reset the linked list
    l.head = NULL;
    l.tail = NULL;
}

void xoaHoaDonODau(ListNode &l)
{
    if (l.head == nullptr)
    {
        cout << "\nDanh sach rong. Khong co hoa don de xoa.\n";
        return;
    }

    NodeHoaDon *p = l.head;
    l.head = l.head->next;

    delete p; // Free memory of the deleted node

    if (l.head == nullptr)
    {
        l.tail = nullptr; // Update the tail if the list becomes empty
    }

    cout << "\nXoa hoa don dau tien thanh cong.\n";
}

// Function to delete a bill at the end of the linked list
void xoaHoaDonOCuoi(ListNode &l)
{
    if (l.head == nullptr)
    {
        cout << "\nDanh sach rong. Khong co hoa don de xoa.\n";
        return;
    }

    if (l.head == l.tail)
    {
        // If there is only one node in the list
        delete l.head;
        l.head = nullptr;
        l.tail = nullptr;
        cout << "\nXoa hoa don thanh cong.\n";
        return;
    }

    NodeHoaDon *p = l.head;
    while (p->next != l.tail)
    {
        p = p->next;
    }

    delete l.tail; // Free memory of the deleted node
    l.tail = p;    // Update the tail to the previous node
    l.tail->next = nullptr;

    cout << "\nXoa hoa don cuoi cung thanh cong.\n";
}

// SAP XEP ------------------------------------------------------------------------------

void swap(NodeHoaDon *a, NodeHoaDon *b)
{
    HoaDon temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sapXepHoaDonTheoTongTienTangDan(ListNode &l)
{
    NodeHoaDon *p, *q;
    int swapped;

    if (l.head == NULL)
    {
        cout << "\nDanh sach rong!";
        return;
    }

    do
    {
        swapped = 0;
        p = l.head;

        for (p = l.head; p->next != NULL; p = p->next)
        {
            q = p->next;

            if (tongTienThanhToanCua1HoaDon(p->data) < tongTienThanhToanCua1HoaDon(q->data))
            {
                swap(p, q);
                swapped = 1;
            }
        }
    } while (swapped);
}

void sapXepHoaDonTheoSoLuongVatLieuXayDungTangDan(ListNode &l)
{
    NodeHoaDon *p, *q;
    int swapped;

    if (l.head == NULL)
    {
        cout << "\nDanh sach rong!";
        return;
    }

    do
    {
        swapped = 0;
        p = l.head;

        for (p = l.head; p->next != NULL; p = p->next)
        {
            q = p->next;

            if (tongSoLuongVLXD(p->data) > tongSoLuongVLXD(q->data))
            {
                swap(p, q);
                swapped = 1;
            }
        }
    } while (swapped);
}

void sapXepHoaDonTheoTenKhachHangChuanAnphalBet(ListNode &l)
{
    NodeHoaDon *p, *q;
    int swapped;
    if (p == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }

    do
    {
        swapped = 0;
        for (p = l.head; p->next; p = p->next)
        {
            q = p->next;
            if (p->data.kh[0].sTenKH > q->data.kh[0].sTenKH)
            {
                swap(p, q);
                swapped = 1;
            }
        }
    } while (swapped);
}

// TIM KIEM ------------------------------------------------------------------------------

void timKiemHoaDonTheoSoHoaDon(ListNode l, int soHoaDon)
{
    int dem = 0;
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        if (soHoaDon == p->data.iSoHD)
        {
            dem++;
            inThongTinHoaDon(p->data);
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong tim thay so hoa don " << soHoaDon << " trong danh sach hoa don 😥" << endl;
    }
}

void timKiemHoaDonTheoTenKhachHang(ListNode l, string tenKH)
{
    int dem = 0;
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        if (tenKH == p->data.kh[0].sTenKH)
        {
            inThongTinHoaDon(p->data);
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong tim thay " << tenKH << " trong danh sach hoa don 😥" << endl;
    }
}

void timKiemHoaDonODiaDiemX(ListNode l, string tenDiaDiem)
{
    NodeHoaDon *p;
    int dem = 0;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        if (tenDiaDiem == p->data.kh[0].sDiaChi)
        {
            dem++;
            inThongTinHoaDon(p->data);
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong co dia diem " << tenDiaDiem << " trong danh sach hoa don 😥" << endl;
    }
}

void timKiemMatHangBanChayNhat(ListNode l)
{
    map<string, int> myMap;

    NodeHoaDon *p;
    for (p = l.head; p != nullptr; p = p->next)
    {
        for (int i = 0; i < slvlxd; i++)
        {
            string itemName = p->data.vlxd[i].sTenHang;
            int itemQuantity = p->data.vlxd[i].iSoLuong;

            // Update the quantity in the map
            myMap[itemName] += itemQuantity;
        }
    }

    cout << "\n\t\t\t ---MAT-HANG-DUOC-BAN-CHAY-NHAT---\n";
    auto maxElement = max_element(myMap.begin(), myMap.end(),
                                  [](const auto &p1, const auto &p2)
                                  {
                                      return p1.second < p2.second;
                                  });

    cout << "\t\t\tTen hang: " << maxElement->first << " --- So luong ban: " << maxElement->second << endl;
}

void timKiemTenKhachHangMuaHangItNhat(ListNode l)
{
    map<string, int> myMap;
    NodeHoaDon *p;
    // Duyệt qua danh sách các hóa đơn
    for (NodeHoaDon *p = l.head; p != NULL; p = p->next)
    {
        // Lấy mã khách hàng của hóa đơn hiện tại
        string maKH = p->data.kh[0].sMaKH;

        // Nếu mã khách hàng chưa có trong map, thêm vào map
        if (myMap.find(maKH) == myMap.end())
        {
            myMap[maKH] = 0;
        }

        // Thêm tổng tiền của hóa đơn hiện tại vào tổng tiền của khách hàng
        myMap[maKH] += tongSoLuongVLXD(p->data);
    }
    // In ra tổng tiền của từng khách hàng

    auto minElement = min_element(myMap.begin(), myMap.end(),
                                  [](const auto &p1, const auto &p2)
                                  {
                                      return p1.second < p2.second;
                                  });

    cout << "\n\t\t\t---KHACH-HANG-MUA-SO-LUONG-HANG-NHO-NHAT LA---\n";

    for (p = l.head; p != NULL; p = p->next)
    {
        if (p->data.kh[0].sMaKH == minElement->first)
        {
            inThongTinKhachHang(p->data.kh[0]);
        }
    }
    cout << "So Luong: " << minElement->second << endl;
}

void timKiemKhachHangChiNhieuTienMuaHangNhat(ListNode l)
{
    // Khởi tạo một map để lưu trữ tổng tiền của từng khách hàng
    map<string, double> myMap;
    NodeHoaDon *p;

    // Duyệt qua danh sách các hóa đơn
    for (NodeHoaDon *p = l.head; p != NULL; p = p->next)
    {
        // Lấy mã khách hàng của hóa đơn hiện tại
        string maKH = p->data.kh[0].sMaKH;

        // Nếu mã khách hàng chưa có trong map, thêm vào map
        if (myMap.find(maKH) == myMap.end())
        {
            myMap[maKH] = 0;
        }

        // Thêm tổng tiền của hóa đơn hiện tại vào tổng tiền của khách hàng
        myMap[maKH] += tongTienThanhToanCua1HoaDon(p->data);
    }

    // In ra tổng tiền của từng khách hàng

    auto maxElement = max_element(myMap.begin(), myMap.end(),
                                  [](const auto &p1, const auto &p2)
                                  {
                                      return p1.second < p2.second;
                                  });

    cout << "\n\t\t\t---KHACH-HANG-CHI-NHIEU-TIEN-MUA-HANG-NHAT-LA---\n";

    for (p = l.head; p != NULL; p = p->next)
    {
        if (p->data.kh[0].sMaKH == maxElement->first)
        {
            inThongTinKhachHang(p->data.kh[0]);
        }
    }
    cout << "Tong tien: " << maxElement->second << " VNĐ" << endl;
}

// TINH TOAN ------------------------------------------------------------------------------

long long tinhTongTienHangDaBan(ListNode l)
{
    double tongTienHang = 0;
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return 0;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        tongTienHang = tongTienHang + tongTienThanhToanCua1HoaDon(p->data);
    }
    return tongTienHang;
}

int tinhTongSoLuongHangDaBan(ListNode l)
{
    int tongHangDaBan = 0;
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return 0;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        tongHangDaBan = tongHangDaBan + tongSoLuongVLXD(p->data);
    }
    return tongHangDaBan;
}

double trungBinhSoTienCuaMoiMatHang(ListNode l)
{
    double trungBinh;
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return 0;
    }
    for (p = l.head; p != NULL; p = p->next)
    {
        trungBinh = tinhTongTienHangDaBan(l) / tinhTongSoLuongHangDaBan(l);
    }
    return trungBinh;
}

void demSoLuongKhachMuaHang(ListNode l)
{
    // dem theo ma khach hang
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    set<int> s;
    for (p = l.head; p != NULL; p = p->next)
    {
        int maKh = stoi(p->data.kh[0].sMaKH);
        s.insert(maKh);
    }
    cout << "\nSo luong khach hang da mua hang cua tat ca cac hoa don la: " << s.size() << endl;
}

void demSoLuongMatHangDaBan(ListNode l)
{
    map<string, int> itemQuantityMap;

    NodeHoaDon *p;
    for (p = l.head; p != nullptr; p = p->next)
    {
        for (int i = 0; i < slvlxd; i++)
        {
            string itemName = p->data.vlxd[i].sTenHang;
            int itemQuantity = p->data.vlxd[i].iSoLuong;

            // Update the quantity in the map
            itemQuantityMap[itemName] += itemQuantity;
        }
    }

    // Display the results
    cout << "\n\t\t\t--- SO-LUONG-MOI-MAT-HANG-DUOC-BAN-LA ---\n";
    for (const auto &pair : itemQuantityMap)
    {
        cout << "\t\t\tMat hang: " << pair.first << " --- So luong da ban: " << pair.second << endl;
    }
}

// THONG KE ------------------------------------------------------------------------------

void thongKeHoaDonCoSoLuongBanHonX(ListNode l, int x)
{
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    int dem = 0;
    for (p = l.head; p != NULL; p = p->next)
    {
        if (tongSoLuongVLXD(p->data) > x)
        {
            inThongTinHoaDon(p->data);
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong co hoa don nao thoa man dieu kien 😥" << endl;
    }
}

void thongKeHoaDonCoTongSoTienHonY(ListNode l, double y)
{
    NodeHoaDon *p;
    if (l.head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    int dem = 0;
    for (p = l.head; p != NULL; p = p->next)
    {
        if (tongTienThanhToanCua1HoaDon(p->data) > y)
        {
            inThongTinHoaDon(p->data);
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong co hoa don nao thoa man dieu kien 😥" << endl;
    }
}

void menu()
{
    int luachon;
    string tenKh;
    ListNode l;
    init(l);
    while (true)
    {
        cout << "\t\t\t---------------------------------------MENU--------------------------------------" << endl;
        cout << "\t\t\t 1. ---  ✍️nhap danh sach hoa don                                            ---" << endl;
        cout << "\t\t\t 2. ---  📝hien thi danh sach hoa don                                        ---" << endl;
        cout << "\t\t\t 3. ---  🗃️cap nhat danh sach vao file                                       ---" << endl;
        cout << "\t\t\t 4. ---  🗂️doc danh sach len tu file                                         ---" << endl;
        cout << "\t\t\t 5. ---  🗑️xoa du lieu file                                                  ---" << endl;
        cout << "\t\t\t 6. ---  🗑️xoa hoa don o dau danh sach                                       ---" << endl;
        cout << "\t\t\t 7. ---  🗑️xoa hoa don o cuoi danh sach                                      ---" << endl;
        cout << "\t\t\t 8. ---  📍sap xep danh sach hoa don theo tong tien hang giam dan            ---" << endl;
        cout << "\t\t\t 9. ---  📍sap xep danh sach hoa don theo tong so vlxd tang dan              ---" << endl;
        cout << "\t\t\t10. ---  📍sap xep danh sach hoa don theo ten khach hang theo chuan alphabet ---" << endl;
        cout << "\t\t\t11. ---  🔍tim kiem hoa don theo so hoa don                                  ---" << endl;
        cout << "\t\t\t12. ---  🔍tim kiem hoa don theo ten khach hang                              ---" << endl;
        cout << "\t\t\t13. ---  🔍tim kiem hoa don ban cho khach o 1 dia diem X                     ---" << endl;
        cout << "\t\t\t14. ---  🔍tim kiem vat ten lieu duoc ban chay nhat                          ---" << endl;
        cout << "\t\t\t15. ---  🔍tim kiem ten khach hang mua hang it nhat                          ---" << endl;
        cout << "\t\t\t16. ---  🔍tim kiem ten khach hang chi nhieu tien mua hang nhat              ---" << endl;
        cout << "\t\t\t17. ---  📱tinh tong so tien hang da ban                                     ---" << endl;
        cout << "\t\t\t18. ---  📱tinh tong so luong hang da ban                                    ---" << endl;
        cout << "\t\t\t19. ---  📱tinh trung binh so tien cua moi mat hang                          ---" << endl;
        cout << "\t\t\t20. ---  📱dem so luong khach hang da mua hang                               ---" << endl;
        cout << "\t\t\t21. ---  📱dem so luong mua hang cua tung mat hang                           ---" << endl;
        cout << "\t\t\t22. ---  📈thong ke hoa don co so luong ban > X mon hang                     ---" << endl;
        cout << "\t\t\t23. ---  📈thong ke hoa don co tong tien > Y VNĐ                             ---" << endl;
        cout << "\t\t\t 0. ---  ❌thoat chuong trinh                                                ---" << endl;
        cout << "\t\t\t --------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t |              [24] --- ✅THONG TIN VE DOI NGU PHAT TRIEN ©                    |" << endl;
        cout << "\t\t\t --------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t 👉Moi ban chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            init(l);
            nhapDSHoaDon(l);
            system("pause");
            system("cls");
            break;
        }

        case 2:
        {
            inDSHoaDon(l);
            system("pause");
            system("cls");
            break;
        }

        case 3:
            ghiFileDSHoaDon(l);
            system("pause");
            system("cls");
            break;

        case 4:
            giaiPhongBoNho(l);
            docFileHoaDon(l);
            inDSHoaDon(l); // In danh sách sau khi đọc từ file
            system("pause");
            system("cls");
            break;

        case 5:
            xoaFile("hoaDon.txt");
            system("pause");
            system("cls");
            break;

        case 6:
            xoaHoaDonODau(l);
            system("pause");
            system("cls");
            break;

        case 7:
            xoaHoaDonOCuoi(l);
            system("pause");
            system("cls");
            break;

        case 8:
            sapXepHoaDonTheoTongTienTangDan(l);
            inDSHoaDon(l);
            system("pause");
            system("cls");
            break;

        case 9:
            sapXepHoaDonTheoSoLuongVatLieuXayDungTangDan(l);
            inDSHoaDon(l);
            system("pause");
            system("cls");
            break;

        case 10:
            sapXepHoaDonTheoTenKhachHangChuanAnphalBet(l);
            inDSHoaDon(l);
            system("pause");
            system("cls");
            break;

        case 11:
        {
            int soHoaDon;
            cout << "\nNhap so hoa don can tim: ";
            cin >> soHoaDon;
            timKiemHoaDonTheoSoHoaDon(l, soHoaDon);
            system("pause");
            system("cls");
            break;
        }

        case 12:
        {
            cin.ignore();
            cout << "\nNhap ten khach hang can tim: ";
            getline(cin, tenKh);
            timKiemHoaDonTheoTenKhachHang(l, tenKh);
            system("pause");
            system("cls");
            break;
        }

        case 13:
        {
            cin.ignore();
            string tenDiaDiem;
            cout << "Nhap ten dia diem can tim: ";
            getline(cin, tenDiaDiem);
            timKiemHoaDonODiaDiemX(l, tenDiaDiem);
            system("pause");
            system("cls");
            break;
        }

        case 14:
            timKiemMatHangBanChayNhat(l);
            system("pause");
            system("cls");
            break;

        case 15:
            timKiemKhachHangChiNhieuTienMuaHangNhat(l);
            system("pause");
            system("cls");
            break;

        case 16:
            timKiemTenKhachHangMuaHangItNhat(l);
            system("pause");
            system("cls");
            break;

        case 17:
            cout << "\nTong tien hang da ban tu truoc den nay la: " << tinhTongTienHangDaBan(l) << " VNĐ" << endl;
            system("pause");
            system("cls");
            break;

        case 18:
            cout << "\nTong so luong hang da ban tu truoc den nay la: " << tinhTongSoLuongHangDaBan(l) << endl;
            system("pause");
            system("cls");
            break;

        case 19:
            cout << "\nTrung binh gia cua 1 mat hang trong hoa don la: " << fixed << setprecision(2) << trungBinhSoTienCuaMoiMatHang(l) << endl;
            system("pause");
            system("cls");
            break;

        case 20:
            demSoLuongKhachMuaHang(l);
            system("pause");
            system("cls");
            break;

        case 21:
            demSoLuongMatHangDaBan(l);
            system("pause");
            system("cls");
            break;

        case 22:
            int x;
            cout << "\nNhap so luong ban: ";
            cin >> x;
            thongKeHoaDonCoSoLuongBanHonX(l, x);
            system("pause");
            system("cls");
            break;

        case 23:
            double y;
            cout << "\nNhap so tien: ";
            cin >> y;
            thongKeHoaDonCoTongSoTienHonY(l, y);
            system("pause");
            system("cls");
            break;

        case 24:
            cout <<"\n\t\t\t 😎 TRAN ANH QUAN -- MSV: 22A1001D0275 -- 2210A03\n";
            system("pause");
            system("cls");
            break;

        case 0:
        {
            exit(1);
            break;
        }

        default:
            cout << "\n Vui long nhap dung lua chon phu hop!!!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

int main()
{
    menu();
    system("pause");
    return 0;
}
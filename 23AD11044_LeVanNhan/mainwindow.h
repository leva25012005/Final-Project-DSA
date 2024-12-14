#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <qlabel.h>
#include "BSTPhone.h"
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui {
class chartWidget;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int currentPage = 1;                // Trang hiện tại
    const int itemsPerPage = 10;        // Số lượng mục hiển thị trên mỗi trang
    int totalItems;                     // Tổng số mục trong cây
    int totalPages;


private slots:

    // Chức năng phân trang
    void PaginationInWidget(QTreeWidget* treeWidget, BSTPhone* treeRoot);
    void ShowPage(QTreeWidget* widget, const std::vector<PhoneInformation>& nodes, int currentPage);
    void showTreeInWidget(QTreeWidget* treeWidget, BSTPhone* treeRoot);
    // Sao chép cây
    BSTPhone* CopyTree(BSTPhone* node);

    // Button quay thay đổi trang
    void btnPrePage_2_clicked();
    void btnNextP_2_clicked();

    // Hiện thi thông tin khi chọn vào 1 hàng
    void treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    // CRUD
    // Thêm một phần tử mới vào cây
    void btnAdd_2_clicked();
    // Xóa một phần tử trng cây
    void btnDelete_2_clicked();
    // Cập nhật phần tử trong cây
    void btnUpdate_2_clicked();

    // Lưu File
    void btnSave_clicked();

    // Reset
    void btnClear_clicked();

    // Sort
    void cbSort_2_currentIndexChanged(int index);

    // CHọn trang
    void onPageChanged(int page);

    // Sự kiện trích lọc
    void onChangedIndex();
    void btnFilter_clicked();
    void FindCriteria(PhoneInformation data, QVector<int>& storageArr, QVector<int>& ramArr, QVector<int>& yearArr);
    // SEARCH
    void onSearchTextChanged(const QString &text);
    void cbSearch_2_currentIndexChanged(int index);

    void on_cbS_currentIndexChanged(int index);

    void on_cbR_currentIndexChanged(int index);

    void on_cbY_currentIndexChanged(int index);

    void showGraph(); // Slot hiển thị và ẩn đồ thị
    // SỰ KIỆN THAY ĐỔI KÍCH THƯỢC GRAPH
    void wheelEvent(QWheelEvent *event);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::chartWidget *ui;

    // Đọc file CSV mặc định ngay khi khởi động
    QString filePathDestination = "E:\\Subject\\HK1_24-25\\Data Structure and Algorithms\\Project_DSA\\FinalProject_DSA-main\\Final-Project-DSA\\23AD11044_LeVanNhan\\Phone3.csv";  // Đường dẫn tới file CSV
    QString filePathSource = "E:\\Subject\\HK1_24-25\\Data Structure and Algorithms\\Project_DSA\\FinalProject_DSA-main\\Final-Project-DSA\\23AD11044_LeVanNhan\\Phone4.csv";  // Đường dẫn tới file CSV
    BSTPhone* treeRoot = ReadCSV(filePathSource.toStdString());
    BSTPhone* originalTreeRoot = nullptr;

    bool isPaginationEnabled = true;  // Mặc định là bật phân trang
    vector<PhoneInformation> filteredNodes; // Danh sách node sau khi lọc
    bool isFiltered = false; // Trạng thái lọc

    QVector<int> storageArr = {0, 32, 64, 128, 256, 512, 1024};
    QVector<int> ramArr = {0, 2, 3, 4, 6, 8, 12, 16, 24};
    QVector<int> yearArr = {0, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024};
};
#endif // MAINWINDOW_H

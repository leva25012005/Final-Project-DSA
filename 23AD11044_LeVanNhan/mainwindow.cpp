#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "BSTPhone.h"
#include <QMessageBox>
#include <QDebug>
#include <qpainter.h>
#include <QStyleOptionSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>
#include <QStringList>
#include <qscrollbar.h>
#include <string>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QWheelEvent>  // Cung cấp sự kiện cuộn chuột
#include <QMouseEvent>  // Cung cấp sự kiện chuột (nhấn, di chuyển, thả chuột)
#include <QGraphicsView>  // Dùng cho đồ họa
#include <QGraphicsScene>  // Dùng cho đồ họa
#include <QPoint>  // Dùng để xử lý toạ độ chuột
//#include <QScrollBar>

void DisplayTree(QTreeWidget* treeWidget, BSTPhone* node, int start, int end, int& currentCount) {
    if (node == nullptr) return;

    // Duyệt cây con bên trái
    DisplayTree(treeWidget, node->left, start, end, currentCount);
    //urrentCount++;

    // Nếu mục hiện tại nằm ngoài phạm vi hiển thị thì bỏ qua
    if (currentCount >= start && currentCount < end) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString::number(node->data.PhoneID));
        item->setText(1, QString::fromStdString(node->data.PhoneBrand));
        item->setText(2, QString::fromStdString(node->data.PhoneModel));
        item->setText(3, QString::fromStdString(node->data.PhoneChipset));
        item->setText(4, QString::fromStdString(node->data.PhoneGPU));
        item->setText(5, QString::number(node->data.PhoneStorage));
        item->setText(6, QString::number(node->data.PhoneRam));
        item->setText(7, QString::number(node->data.PhonePrice));
        item->setText(8, QString::number(node->data.PhoneYear));
        treeWidget->addTopLevelItem(item);
    }

    currentCount++;

    // Duyệt cây con bên phải
    DisplayTree(treeWidget, node->right, start, end, currentCount);

}
void DisplayTree(QTreeWidget* treeWidget, BSTPhone* node){
    if (node == nullptr) return;

    // Duyệt cây con bên trái
    DisplayTree(treeWidget, node->left);

    // Tạo mục cho node hiện tại
    QTreeWidgetItem* item = new QTreeWidgetItem();

    // Cập nhật các cột hiển thị thông tin của phone
    item->setText(0, QString::number(node->data.PhoneID));             // Cột 1: PhoneID
    item->setText(1, QString::fromStdString(node->data.PhoneBrand));   // Cột 2: PhoneBrand
    item->setText(2, QString::fromStdString(node->data.PhoneModel));   // Cột 3: PhoneModel
    item->setText(3, QString::fromStdString(node->data.PhoneChipset)); // Cột 4: PhoneChipset
    item->setText(4, QString::fromStdString(node->data.PhoneGPU));     // Cột 5: PhoneGPU
    item->setText(5, QString::number(node->data.PhoneStorage));        // Cột 6: PhoneStorage
    item->setText(6, QString::number(node->data.PhoneRam));            // Cột 7: PhoneRam
    item->setText(7, QString::number(node->data.PhonePrice));          // Cột 8: PhonePrice
    item->setText(8, QString::number(node->data.PhoneYear));           // Cột 9: PhoneYear

    // Thêm item vào QTreeWidget
    treeWidget->addTopLevelItem(item);

    // Duyệt qua các cây con bên phải
    DisplayTree(treeWidget, node->right);
}
void MainWindow::ShowPage(QTreeWidget* widget, const std::vector<PhoneInformation>& nodes, int currentPage) {
    widget->clear(); // Xóa dữ liệu cũ trong bảng

    if (nodes.empty()) { // Kiểm tra nếu danh sách trống
        QMessageBox::information(this, "No Data", "No data available to display.");
        return;
    }

    // Xác định phạm vi dữ liệu hiển thị trên trang hiện tại
    int start = (currentPage - 1) * itemsPerPage;
    int end = std::min(start + itemsPerPage, static_cast<int>(nodes.size())); // Đảm bảo không vượt quá kích thước
    // Hiển thị dữ liệu
    for (int i = start; i < end; ++i) {
        QTreeWidgetItem* item = new QTreeWidgetItem(widget);
        // Cập nhật các cột hiển thị thông tin của phone
        item->setText(0, QString::number(nodes[i].PhoneID));             // Cột 1: PhoneID
        item->setText(1, QString::fromStdString(nodes[i].PhoneBrand));   // Cột 2: PhoneBrand
        item->setText(2, QString::fromStdString(nodes[i].PhoneModel));   // Cột 3: PhoneModel
        item->setText(3, QString::fromStdString(nodes[i].PhoneChipset)); // Cột 4: PhoneChipset
        item->setText(4, QString::fromStdString(nodes[i].PhoneGPU));     // Cột 5: PhoneGPU
        item->setText(5, QString::number(nodes[i].PhoneStorage));        // Cột 6: PhoneStorage
        item->setText(6, QString::number(nodes[i].PhoneRam));            // Cột 7: PhoneRam
        item->setText(7, QString::number(nodes[i].PhonePrice));          // Cột 8: PhonePrice
        item->setText(8, QString::number(nodes[i].PhoneYear));           // Cột 9: PhoneYear
        widget->addTopLevelItem(item);
    }

    //ui->sbPage->hide();
    //ui->lbPage->hide();
}
void MainWindow::showTreeInWidget(QTreeWidget* treeWidget, BSTPhone* treeRoot) {
    // Tạo cây BST từ dữ liệu CSV
    treeWidget->clear();
    DisplayTree(treeWidget, treeRoot);
}
// Hàm phân trnag
void MainWindow::PaginationInWidget(QTreeWidget* treeWidget, BSTPhone* treeRoot) {
    // Tính phạm vi hiển thị
    int start = (currentPage - 1) * itemsPerPage;
    int end = start + itemsPerPage;

    int index = 0;

    DisplayTree(treeWidget, treeRoot, start, end, index);
    //ui->lbPage->setText(QString("Page: %1").arg(currentPage));
    ui->sbPage->setValue(currentPage);

}
// Sao chép cây
BSTPhone* MainWindow::CopyTree(BSTPhone* node) {
    if (node == nullptr) return nullptr;

    // Tạo nút mới
    BSTPhone* newNode = new BSTPhone;
    newNode->data = node->data;
    newNode->left = CopyTree(node->left);  // Sao chép cây con bên trái
    newNode->right = CopyTree(node->right); // Sao chép cây con bên phải

    return newNode;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chartWidget)
{
    ui->setupUi(this);

    ui->txt_total->setVisible(false);

    // Đặt kích thước cố định cho cửa sổ
    this->setFixedSize(1000, 700);

    // Hiển thị cây trong QTreeWidget
    PaginationInWidget(ui->treeWidget,treeRoot);
    //showTreeInWidget(ui->treeWidget, treeRoot);
    // Lưu bản sao cây gốc
    originalTreeRoot = CopyTree(treeRoot); // Hàm CopyTree để tạo bản sao cây

    // Tính toán tổng số mục và số trang
    totalItems = countNodes(treeRoot);
    totalPages = (totalItems / itemsPerPage) + (totalPages % itemsPerPage > 0 ? 1 : 0);

    // Giới hạn cho spin box
    ui->sbPage->setRange(1, totalPages);

    // Kết nối nút Previous Page
    connect(ui->btnPrePage_2, &QPushButton::clicked, this, &MainWindow::btnPrePage_2_clicked);

    // Kết nối nút Next Page
    connect(ui->btnNextP_2, &QPushButton::clicked, this, &MainWindow::btnNextP_2_clicked);

    // Kết nối sự kiện item clicked của treeWidget
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::treeWidget_itemClicked);

    // Kết nối sự kiện cho button add
    connect(ui->btnAdd_2,&QPushButton::clicked,this,&MainWindow::btnAdd_2_clicked);

    // Kết nối sự kiện cho button del
    connect(ui->btnDelete_2, &QPushButton::clicked, this, &MainWindow::btnDelete_2_clicked);

    // kết nối sự kiện cho button update
    connect(ui->btnUpdate_2, &QPushButton::clicked, this, &MainWindow::btnUpdate_2_clicked);

    // Kết nối sự kiện cho button save
    connect(ui->btnSave,  &QPushButton::clicked, this, &MainWindow::btnSave_clicked);

    // Kết nối sự kiện cho button Reset
    connect(ui->btnClear,  &QPushButton::clicked, this, &MainWindow::btnClear_clicked);

    // Kết nối sự kiện cho commbo box Sort
    connect(ui->cbSort_2, SIGNAL(currentIndexChanged(int)), this, SLOT(cbSort_2_currentIndexChanged(int)));

    // Kết nối sự kiện cho spin box
    connect(ui->sbPage, SIGNAL(valueChanged(int)), this, SLOT(onPageChanged(int)));

    // Kết nối sự kiện cho button Filter
    connect(ui->btnFilter, &QPushButton::clicked, this, &MainWindow::btnFilter_clicked);

    // Kết nối sự kiện cho text search
    connect(ui->txtSearch_2, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    //connect(ui->txtSearch_2, &QLineEdit::textChanged, this, &MainWindow::on_btnSearch_clicked);
    // Kết nói sự kiện cho combo box search
    connect(ui->cbSearch_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::cbSearch_2_currentIndexChanged);

    // Kết nối sự kiện cho combo box filter sau khi được thêm giá trị mới
    ui->btnFilter->setEnabled(false);
    connect(ui->cbS, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbS_currentIndexChanged(int)));
    connect(ui->cbR, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbR_currentIndexChanged(int)));
    connect(ui->cbY, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbY_currentIndexChanged(int)));
}

MainWindow::~MainWindow()
{
    DeleteTree(treeRoot);
    DeleteTree(originalTreeRoot); // Xóa bản sao cây gốc
    delete ui;
}

// Button thay đổi trang
void MainWindow::btnNextP_2_clicked()
{
    if (currentPage < totalPages) {
        // Nếu chưa đến trang cuối, tăng currentPage lên 1
        currentPage++;
        if (isFiltered) { // Nếu đang lọc
            ui->sbPage->setValue(currentPage);
            ShowPage(ui->treeWidget, filteredNodes, currentPage);
        } else { // Hiển thị toàn bộ dữ liệu
            PaginationInWidget(ui->treeWidget, treeRoot);
        }
    } else
    {
        QMessageBox::information(this, "Notification", "You have reached the last page.");
        return;
    }

}
void MainWindow::btnPrePage_2_clicked()
{
    //ui->treeWidget->clear();

    if (currentPage > 1)
    {
        currentPage--;
        if (isFiltered)  // Nếu đang lọc
        {
            ui->sbPage->setValue(currentPage);
            ShowPage(ui->treeWidget, filteredNodes, currentPage);
        }
        else PaginationInWidget(ui->treeWidget, treeRoot);
    }
    else
    {
        //currentPage++;
        QMessageBox::information(this, "Notification", "You have reached the first page.");
        return;
    }
}
// Hiện thi thông tin khi chọn vào 1 hàng
void MainWindow::treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    // Lấy thông tin từ mục được chọn trong treeWidget
    int id = item->text(0).toInt();           // PhoneID (Cột 1)
    QString brand = item->text(1);            // PhoneBrand (Cột 2)
    QString model = item->text(2);            // PhoneModel (Cột 3)
    QString chipset = item->text(3);          // PhoneChipset (Cột 4)
    QString gpu = item->text(4);              // PhoneGPU (Cột 5)
    int storage = item->text(5).toInt();      // PhoneStorage (Cột 6)
    int ram = item->text(6).toInt();          // PhoneRam (Cột 7)
    double price = item->text(7).toDouble();  // PhonePrice (Cột 8)
    int year = item->text(8).toInt();         // PhoneYear (Cột 9)

    // Cập nhật giá trị lên các QLineEdit
    ui->txtID_2->setText(QString::number(id));
    ui->txtBrand_2->setText(brand);
    ui->txtModel_2->setText(model);
    ui->txtChipset_2->setText(chipset);
    ui->txtGPU_2->setText(gpu);
    ui->txtStorage_2->setText(QString::number(storage));
    ui->txtRam_2->setText(QString::number(ram));
    ui->txtPrice_2->setText(QString::number(price));
    ui->txtYear_2->setText(QString::number(year));

    // Đặt txtID thành chỉ đọc (không thể chỉnh sửa)
    ui->txtID_2->setReadOnly(true);
}
// CRUD
// Thêm một phần tử mới vào cây
// Hàm duyệt nếu có giá trị mới
void MainWindow::FindCriteria(PhoneInformation data, QVector<int>& storageArr, QVector<int>& ramArr, QVector<int>& yearArr)
{
    // Kiểm tra và thêm vào các vector nếu giá trị chưa có
    if (!storageArr.contains(data.PhoneStorage)) {
        storageArr.push_back(data.PhoneStorage);
    }

    if (!ramArr.contains(data.PhoneRam)) {
        ramArr.push_back(data.PhoneRam);
    }

    if (!yearArr.contains(data.PhoneYear)) {
        yearArr.push_back(data.PhoneYear);
    }

    // Sắp xếp lại các vector theo thứ tự tăng dần
    std::sort(storageArr.begin(), storageArr.end());
    std::sort(ramArr.begin(), ramArr.end());
    std::sort(yearArr.begin(), yearArr.end());

    // Lấy con trỏ tới combo box trong giao diện (Giả sử bạn có các combo box)
    QComboBox* storageComboBox = ui->cbS;  // ComboBox cho Storage
    QComboBox* ramComboBox = ui->cbR;          // ComboBox cho RAM
    QComboBox* yearComboBox = ui->cbY;        // ComboBox cho Year

    // Làm trống combo box trước khi thêm giá trị mới
    storageComboBox->clear();
    ramComboBox->clear();
    yearComboBox->clear();

    // Thêm "all" vào đầu combo box
    storageComboBox->addItem("All");
    ramComboBox->addItem("All");
    yearComboBox->addItem("All");

    // Thêm các giá trị vào combo box từ các vector đã sắp xếp
    for(int i = 0; i < storageArr.size(); i++)
        storageComboBox->addItem(QString::number(storageArr[i]));  // Thêm từng phần tử vào combo box
    ui->cbS->removeItem(1);

    for(int i = 0; i < ramArr.size(); i++)
        ramComboBox->addItem(QString::number(ramArr[i]));  // Thêm từng phần tử vào combo box
    ui->cbR->removeItem(1);

    for(int i = 0; i < yearArr.size(); i++)
        yearComboBox->addItem(QString::number(yearArr[i]));  // Thêm từng phần tử vào combo box
    ui->cbY->removeItem(1);
    ui->btnFilter->setEnabled(false);
}
void MainWindow::btnAdd_2_clicked()
{
    // Lấy thông tin từ các QLineEdit
    PhoneInformation newPhone;

    // Kiểm tra nếu trường nhập liệu trống
    if (ui->txtID_2->text().isEmpty() || ui->txtBrand_2->text().isEmpty() ||
        ui->txtModel_2->text().isEmpty() || ui->txtChipset_2->text().isEmpty() ||
        ui->txtGPU_2->text().isEmpty() || ui->txtStorage_2->text().isEmpty() ||
        ui->txtPrice_2->text().isEmpty() || ui->txtYear_2->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    // Kiểm tra kiểu dữ liệu cho các trường số (ID, Storage, RAM, Price, Year)
    bool ok;
    newPhone.PhoneID = ui->txtID_2->text().toInt(&ok); // nếu chuỗi hợp lệ thì true và ngược lại
    if (!ok || newPhone.PhoneID <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid positive Phone ID.");
        return;
    }else if(FindNode(treeRoot, newPhone.PhoneID))
    {
        QMessageBox::warning(this, "Input Error", "This ID has existed!");
        return;
    }

    newPhone.PhoneStorage = ui->txtStorage_2->text().toInt(&ok);
    if (!ok || newPhone.PhoneStorage <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid positive Storage.");
        return;
    }

    newPhone.PhoneRam = ui->txtRam_2->text().toInt(&ok);
    if (!ok || newPhone.PhoneRam <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid positive RAM.");
        return;
    }

    newPhone.PhonePrice = ui->txtPrice_2->text().toFloat(&ok);
    if (!ok || newPhone.PhonePrice <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid positive Price.");
        return;
    }

    newPhone.PhoneYear = ui->txtYear_2->text().toInt(&ok);
    if (!ok || newPhone.PhoneYear <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid positive Year.");
        return;
    }


    // Kiểm tra các trường chuỗi (Brand, Model, Chipset, GPU)
    newPhone.PhoneBrand = ui->txtBrand_2->text().toStdString();
    newPhone.PhoneModel = ui->txtModel_2->text().toStdString();
    newPhone.PhoneChipset = ui->txtChipset_2->text().toStdString();
    newPhone.PhoneGPU = ui->txtGPU_2->text().toStdString();

    // Kiểm tra nếu các chuỗi không rỗng
    if (newPhone.PhoneBrand.empty() || newPhone.PhoneModel.empty() ||
        newPhone.PhoneChipset.empty() || newPhone.PhoneGPU.empty()) {
        QMessageBox::warning(this, "Input Error", "Brand, Model, Chipset and GPU cannot be empty.");
        return;
    }

    // Thêm thông tin điện thoại vào cây BST
    treeRoot = AddPhone(treeRoot, newPhone);

    // Cập nhập giá trị cho combo nếu là giá trị
    FindCriteria(newPhone, storageArr, ramArr, yearArr);

    // Lưu trữ giá trị mới
    originalTreeRoot = CopyTree(treeRoot);

    // Cập nhật cây trên QTreeWidget
    ui->treeWidget->clear();
    PaginationInWidget(ui->treeWidget, treeRoot);

    // Xóa nội dung của các QLineEdit sau khi thêm
    ui->txtID_2->clear();
    ui->txtBrand_2->clear();
    ui->txtModel_2->clear();
    ui->txtChipset_2->clear();
    ui->txtGPU_2->clear();
    ui->txtStorage_2->clear();
    ui->txtRam_2->clear();
    ui->txtPrice_2->clear();
    ui->txtYear_2->clear();    

    // Thông báo thành công
    QMessageBox::information(this, "Addition", "Phone added successfully.");

    // Cập nhật brand mới
    showGraph();
}
// Xóa một phần tử trong cây
void MainWindow::btnDelete_2_clicked()
{
    // Lấy ID từ QLineEdit
        int phoneID = ui->txtID_2->text().toInt();

    // Kiểm tra xem ID có hợp lệ không (ví dụ không phải 0 hoặc ID không tồn tại)
    if (phoneID == 0) {
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid Phone ID.");
        return;
    }

    // Thông báo xác nhận xóa
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Addition Confirmation", "DO YOU WANT TO ADD A NEW PHONE?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Xóa điện thoại khỏi cây BST
        treeRoot = DeletePhone(treeRoot, phoneID);

        // Cập nhật lại cây trên QTreeWidget sau khi xóa
        ui->treeWidget->clear();
        PaginationInWidget(ui->treeWidget,treeRoot);

        // Xóa nội dung của các QLineEdit sau khi chọn
        ui->txtID_2->clear();
        ui->txtBrand_2->clear();
        ui->txtModel_2->clear();
        ui->txtChipset_2->clear();
        ui->txtGPU_2->clear();
        ui->txtStorage_2->clear();
        ui->txtRam_2->clear();
        ui->txtPrice_2->clear();
        ui->txtYear_2->clear();

        // Lưu trữ cây sau khi xóa
        originalTreeRoot = CopyTree(treeRoot);

        // Thông báo thành công
        QMessageBox::information(this, "Delete", "Phone deleted successfully.");
    } else {
        // Nếu chọn Cancel, không làm gì cả
        QMessageBox::information(this, "Delete", "Phone deleted cancelled.");
    }



}
// Cập nhật phần tử trong cây
void MainWindow::btnUpdate_2_clicked()
{
    // Lấy thông tin từ các QLineEdit
    int phoneID = ui->txtID_2->text().toInt(); // PhoneID (Cột 1)
    QString brand = ui->txtBrand_2->text();    // PhoneBrand (Cột 2)
    QString model = ui->txtModel_2->text();    // PhoneModel (Cột 3)
    QString chipset = ui->txtChipset_2->text(); // PhoneChipset (Cột 4)
    QString gpu = ui->txtGPU_2->text();         // PhoneGPU (Cột 5)
    int storage = ui->txtStorage_2->text().toInt(); // PhoneStorage (Cột 6)
    int ram = ui->txtRam_2->text().toInt();     // PhoneRam (Cột 7)
    double price = ui->txtPrice_2->text().toDouble(); // PhonePrice (Cột 8)
    int year = ui->txtYear_2->text().toInt();   // PhoneYear (Cột 9)

    // Tạo một đối tượng PhoneInformation mới với thông tin đã nhập
    PhoneInformation updatedPhone;
    updatedPhone.PhoneID = phoneID;
    updatedPhone.PhoneBrand = brand.toStdString();
    updatedPhone.PhoneModel = model.toStdString();
    updatedPhone.PhoneChipset = chipset.toStdString();
    updatedPhone.PhoneGPU = gpu.toStdString();
    updatedPhone.PhoneStorage = storage;
    updatedPhone.PhoneRam = ram;
    updatedPhone.PhonePrice = price;
    updatedPhone.PhoneYear = year;

    // Cập nhật cây BST với thông tin mới
    treeRoot = UpdatePhone(treeRoot, updatedPhone);

    // Lưu trữ cây sau khi cập nhật
    originalTreeRoot = CopyTree(treeRoot);

    // Hiển thị lại cây sau khi cập nhật
    ui->treeWidget->clear();
    PaginationInWidget(ui->treeWidget, treeRoot);

    // Thông báo thành công
    QMessageBox::information(this, "Update", "Phone updated successfully.");
}
// Lưu File
void MainWindow::btnSave_clicked()
{
    WriteCSV(filePathDestination.toStdString(), treeRoot);
    // Hiển thị thông báo thành công
    QMessageBox::information(this, "Save Successful", "Data has been successfully saved to the file.");
}
// Reset
void MainWindow::btnClear_clicked()
{
    // Xóa các trường thông tin
    ui->txtID_2->clear();
    ui->txtBrand_2->clear();
    ui->txtModel_2->clear();
    ui->txtChipset_2->clear();
    ui->txtGPU_2->clear();
    ui->txtStorage_2->clear();
    ui->txtRam_2->clear();
    ui->txtPrice_2->clear();
    ui->txtYear_2->clear();
    ui->txtSearch_2->clear();

    ui->txtID_2->setReadOnly(false);

    isFiltered = false; // Đặt lại trạng thái không lọc
    ui->btnFilter->setEnabled(false);

    treeRoot = CopyTree(originalTreeRoot);
    totalItems = countNodes(treeRoot);
    totalPages = (totalItems / itemsPerPage) + (totalPages % itemsPerPage > 0 ? 1 : 0);
    ui->treeWidget->clear(); // Xóa nội dung cũ
    currentPage = 1;         // Đặt lại trang về 1

    PaginationInWidget(ui->treeWidget, treeRoot); // Hiển thị lại từ cây temp

    // Đặt combobox về lựa chọn "Không sắp xếp" (Case 0)
    ui->cbSort_2->setCurrentIndex(0);
    ui->cbSearch_2->setCurrentIndex(0);
    ui->cbR->setCurrentIndex(0);
    ui->cbS->setCurrentIndex((0));
    ui->cbY->setCurrentIndex(0);

    //
    ui->sbPage->show();
    ui->lbPage->show();

    ui->txt_total->setVisible(false);

}
// Sort
void MainWindow::cbSort_2_currentIndexChanged(int index)
{
    //originalTreeRoot = CopyTree(treeRoot); // Khôi phục từ bản sao

    qint64 elapsed = 0;
    // Chọn loại
    switch(index){
    case 0: // Mặc định
        treeRoot = CopyTree(originalTreeRoot);
        break;
    case 1: // Model a->z  Merge Sort
        treeRoot = CopyTree(originalTreeRoot);
        treeRoot = SortTree(treeRoot, 1, true, elapsed);
        break;
    case 2: // Model z->a Insertion Sort
        treeRoot = CopyTree(originalTreeRoot);
        treeRoot = SortTree(treeRoot, 2, false, elapsed);
        break;
    case 3: // Price - asc Quick Sort
        treeRoot = CopyTree(originalTreeRoot);
        treeRoot = SortTree(treeRoot, 4, true, elapsed);
        break;
    case 4: // Price - desc Bubble Sort
        treeRoot = CopyTree(originalTreeRoot);
        treeRoot = SortTree(treeRoot, 4, false, elapsed);
        break;
    }

    // Cập nhật lại cây sau khi sắp xếp
    currentPage = 1;
    ui->treeWidget->clear();
    PaginationInWidget(ui->treeWidget, treeRoot);

    // Hiển thị thời gian lên giao diện (nếu cần)
    ui->txt_total->setVisible(true);
    ui->txt_total->setText("Sort completed in " + QString::number(elapsed) + " ms");
    ui->txt_total->setStyleSheet("color: yellow");
}


// CHọn trang
void MainWindow::onPageChanged(int page)
{
    currentPage = page;
    ui->treeWidget->clear();
    PaginationInWidget(ui->treeWidget, treeRoot);
}
// Hàm lọc
void FilterNodes(int storage, int ram, int year, BSTPhone* tree, vector<PhoneInformation>& result) {
    if (tree == nullptr) return;

    // Kiểm tra điều kiện và thêm node vào danh sách nếu thỏa mãn
    if ((storage == 0 || storage == tree->data.PhoneStorage) &&
        (ram == 0 || ram == tree->data.PhoneRam) &&
        (year == 0 || year == tree->data.PhoneYear)) {
        result.push_back(tree->data);
    }

    // Duyệt qua cây con trái và phải
    FilterNodes(storage, ram, year, tree->left, result);
    FilterNodes(storage, ram, year, tree->right, result);
}
// Sự kiện trích lọc
void MainWindow::onChangedIndex() {


    // Lưu trữ giá trị cây trước khi trích lọc
    originalTreeRoot = CopyTree(treeRoot);

    int storageIndex = ui->cbS->currentIndex();
    int ramIndex = ui->cbR->currentIndex();
    int yearIndex = ui->cbY->currentIndex();

    // Lưu trữ giá trị cây trước khi trích+
    originalTreeRoot = CopyTree(treeRoot);

    // Làm trống danh sách node đã lọc
    filteredNodes.clear();

    // Lọc dữ liệu từ cây
    FilterNodes(storageArr[storageIndex], ramArr[ramIndex], yearArr[yearIndex], treeRoot, filteredNodes);

    // Cập nhật trạng thái
    isFiltered = true;

    // Kiểm tra nếu danh sách filteredNodes trống
    if (filteredNodes.empty()) {
        // Nếu trống, hiển thị MessageBox
        QMessageBox::information(this, "No Results", "No items found matching the criteria.");
        return;  // Không tiếp tục xử lý nếu danh sách trống
    }

    // Cập nhập trang
    currentPage = 1;
    totalItems = filteredNodes.size();
    qDebug() << "Total items: " << totalItems;
    ui->txt_total->setText("Total items: " + QString::number(totalItems));
    ui->txt_total->setVisible(true);
    totalPages = (totalItems / itemsPerPage);
    if((totalPages % itemsPerPage) > 1) totalPages++;
    // Cập nhật giao diện với trang đầu tiên
    ShowPage(ui->treeWidget, filteredNodes, currentPage);
}

void MainWindow::btnFilter_clicked()
{
        onChangedIndex();
}

// Search
// Kiểm tra xem số nguyên `value` có bắt đầu bằng `prefix` hay không
bool startsWith(int value, const std::string& prefix) {
    return std::to_string(value).find(prefix) == 0;
}
// Hàm tìm kiếm gần đúng trong cây BST
void searchApproximatePhoneID(BSTPhone* root, const std::string& prefix, std::vector<PhoneInformation>& results) {
    if (root == nullptr) return;

    // Duyệt cây bên trái
    searchApproximatePhoneID(root->left, prefix, results);

    // Nếu PhoneID của node hiện tại bắt đầu bằng prefix, thêm vào danh sách kết quả
    if (startsWith(root->data.PhoneID, prefix)) {
        results.push_back(root->data);
    }
    // Duyệt cây bên phải
    searchApproximatePhoneID(root->right, prefix, results);
}
void MainWindow::onSearchTextChanged(const QString &text) {
    ui->treeWidget->clear(); // Xóa kết quả cũ

    if (text.isEmpty()) {
        // Nếu nội dung tìm kiếm trống, hiển thị lại toàn bộ danh sách
        PaginationInWidget(ui->treeWidget, treeRoot);

        ui->btnNextP_2->setEnabled(true);
        ui->btnPrePage_2->setEnabled(true);
        ui->sbPage->setEnabled(true);
        ui->cbSearch_2->setCurrentIndex(0);
        ui->txtSearch_2->clear();
        return;
    }

    if (ui->cbSearch_2->currentIndex() == 1) {
        // Tìm kiếm theo ID
        QString input = ui->txtSearch_2->text();  // Lấy tiền tố PhoneID từ QLineEdit
        std::string prefix = input.toStdString();

        // Danh sách lưu kết quả tìm kiếm
        vector<PhoneInformation> results;

        // Gọi hàm tìm kiếm gần đúng
        searchApproximatePhoneID(treeRoot, prefix, results);

        if (!results.empty()) {
            totalItems = results.size();
            for (const auto& result : results)
            {
                QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
                item->setText(0, QString::number(result.PhoneID));
                item->setText(1, QString::fromStdString(result.PhoneBrand));
                item->setText(2, QString::fromStdString(result.PhoneModel));
                item->setText(3, QString::fromStdString(result.PhoneChipset));
                item->setText(4, QString::fromStdString(result.PhoneGPU));
                item->setText(5, QString::number(result.PhoneStorage));
                item->setText(6, QString::number(result.PhoneRam));
                item->setText(7, QString::number(result.PhonePrice));
                item->setText(8, QString::number(result.PhoneYear));
            }

            //ShowPage(ui->treeWidget, results, currentPage);
            for (const auto& phone : results) {
                qDebug() << "PhoneID: " << phone.PhoneID << "\n";
            }
            qDebug() << totalItems << ' ' << totalPages<< "\n";

        } else {
            // Thông báo nếu không tìm thấy
            QMessageBox::warning(this, "Not Found", "No phones found with the given prefix.");
        }

        ui->btnNextP_2->setEnabled(false);
        ui->btnPrePage_2->setEnabled(false);
        ui->sbPage->setEnabled(false);
    } else if (ui->cbSearch_2->currentIndex() == 2) {
        // Tìm kiếm theo Model
        BSTPhone* resultTree = nullptr; // Cây BST lưu kết quả tìm kiếm
        resultTree = FindNodesByModel(treeRoot, text.toStdString());

        if (resultTree) {
            DisplayTree(ui->treeWidget, resultTree);
        } else {
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0, "Không tìm thấy Model phù hợp");
        }
        DeleteTree(resultTree); // xóa cây sau khi dùng
        ui->btnNextP_2->setEnabled(false);
        ui->btnPrePage_2->setEnabled(false);
        ui->sbPage->setEnabled(false);
    }
}

void MainWindow::cbSearch_2_currentIndexChanged(int index)
{
    if (ui->cbSearch_2->currentIndex() == 0) {
        ui->btnNextP_2->setEnabled(true);
        ui->btnPrePage_2->setEnabled(true);
        ui->sbPage->setEnabled(true);
        ui->cbSearch_2->setCurrentIndex(0);
        ui->txtSearch_2->clear();
        return;
    }
    ui->txtSearch_2->clear();
}

void MainWindow::on_cbS_currentIndexChanged(int index)
{
    if(index != 0)
        ui->btnFilter->setEnabled(true);
}


void MainWindow::on_cbR_currentIndexChanged(int index)
{
    if(index != 0)
        ui->btnFilter->setEnabled(true);
}


void MainWindow::on_cbY_currentIndexChanged(int index)
{
    if(index != 0)
        ui->btnFilter->setEnabled(true);
}

// Visualization
// Đếm số lượng Brend
void CountBrands(BSTPhone* root, map<string, int>& brandCount) {
    if (root == nullptr) return;

    // Tăng số lượng của PhoneBrand tương ứng
    brandCount[root->data.PhoneBrand]++;

    // Duyệt cây trái và phải
    CountBrands(root->left, brandCount);
    CountBrands(root->right, brandCount);
}

// Tính tổng số lượng
map<string, float> calculateBrandPercentage(map<string, int>& brandCount)
{
    map<string, float> percentages;
    int totalPhones = 0;


    for(const auto& brand : brandCount)
        totalPhones +=brand.second;

    for(const auto& brand: brandCount)
        percentages[brand.first] = (brand.second / (float)totalPhones * 100.0f);

    return percentages;
}

void MainWindow::showGraph() {
    // 1. Tạo map để đếm số lượng các Brand
    map<string, int> brandCount;
    CountBrands(treeRoot, brandCount);

    // 2. Tính tỷ lệ phần trăm
    map<string, float> percentages = calculateBrandPercentage(brandCount);

    // 3. Tạo một QGraphicsScene để hiển thị biểu đồ
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(174, 198, 207)));  // Đặt nền

    // 4. Thiết lập kích thước biểu đồ và khoảng cách giữa các cột
    int chartWidth = 800; // Chiều rộng biểu đồ
    int chartHeight = 400; // Chiều cao biểu đồ
    int barWidth = 70; // Tăng độ rộng mỗi cột
    int barSpacing = 0; // Không có khoảng cách giữa các cột (đặt giá trị là 0)
    int xOffset = 50; // Khoảng cách bắt đầu từ trục y
    int yOffset = 50; // Khoảng cách từ trục x đến cột

    // Số lượng các cột
    int columnCount = percentages.size();

    // 5. Tạo danh sách màu sắc độc đáo
    QList<QColor> colors;
    for (int i = 0; i < columnCount; ++i) {
        int hue = (i * 360) / columnCount; // Chia vòng màu sắc thành các phần đều nhau
        colors.append(QColor::fromHsv(hue, 255, 255)); // Tạo màu sắc khác nhau
    }

    // 6. Vẽ các cột
    int index = 0;
    for (const auto& brand : percentages) {
        // Chiều cao của cột, tính theo tỷ lệ phần trăm
        double barHeight = (brand.second / 100.0) * chartHeight;

        // Tạo hình chữ nhật cho cột
        QGraphicsRectItem* bar = new QGraphicsRectItem(
            xOffset + index * barWidth, // Tọa độ x: không cộng khoảng cách, chỉ có chiều rộng cột
            chartHeight - barHeight + yOffset, // Tọa độ y
            barWidth, // Chiều rộng
            barHeight); // Chiều cao

        // Gán màu cho cột từ danh sách màu sắc
        bar->setBrush(QBrush(colors.at(index)));
        scene->addItem(bar);

        // Thêm nhãn phần trăm lên trên cột
        QString percentageText = QString::number(brand.second, 'f', 1) + "%";
        QGraphicsTextItem* percentageLabel = new QGraphicsTextItem(percentageText);
        percentageLabel->setDefaultTextColor(Qt::black); // Màu chữ trắng
        percentageLabel->setPos(
            xOffset + index * barWidth + barWidth / 4, // X (giữa cột)
            chartHeight - barHeight + yOffset - 20); // Y (trên đỉnh cột)
        scene->addItem(percentageLabel);

        // Thêm nhãn tên Brand bên dưới cột
        QGraphicsTextItem* brandLabel = new QGraphicsTextItem(QString::fromStdString(brand.first));
        brandLabel->setDefaultTextColor(Qt::black); // Màu chữ trắng
        brandLabel->setPos(
            xOffset + index * barWidth + barWidth / 4, // X (giữa cột)
            chartHeight + yOffset + 10); // Y (bên dưới cột)
        scene->addItem(brandLabel);

        // Chuyển sang cột tiếp theo
        index++;
    }

    // 7. Vẽ trục tung (thể hiện tỷ lệ phần trăm)
    QGraphicsLineItem* yAxis = new QGraphicsLineItem(xOffset, yOffset, xOffset, chartHeight + yOffset);
    scene->addItem(yAxis);

    // Vẽ mũi tên cho trục tung
    QPolygonF yArrow;
    yArrow << QPointF(xOffset - 5, yOffset + 10) << QPointF(xOffset + 5, yOffset + 10) << QPointF(xOffset, yOffset - 10);
    QGraphicsPolygonItem* yArrowItem = new QGraphicsPolygonItem(yArrow);
    yArrowItem->setBrush(Qt::black); // Màu cho mũi tên
    scene->addItem(yArrowItem);

    // Thêm nhãn cho trục tung
    QGraphicsTextItem* yAxisLabel = new QGraphicsTextItem("%");
    yAxisLabel->setDefaultTextColor(Qt::black);
    yAxisLabel->setPos(xOffset - 30, yOffset - 30); // Đặt nhãn "%"
    scene->addItem(yAxisLabel);

    // 8. Vẽ trục hoành (thể hiện Brand)
    int xAxisLength = (columnCount * barWidth) + 3 * xOffset; // Tổng chiều dài của các cột cộng thêm khoảng cách
    QGraphicsLineItem* xAxis = new QGraphicsLineItem(xOffset, chartHeight + yOffset, xAxisLength, chartHeight + yOffset);
    scene->addItem(xAxis);

    // Tăng độ dài mũi tên cho trục hoành
    QPolygonF xArrow;
    xArrow << QPointF(xAxisLength - 18, chartHeight + yOffset - 5) << QPointF(xAxisLength, chartHeight + yOffset) << QPointF(xAxisLength - 20, chartHeight + yOffset + 5);
    QGraphicsPolygonItem* xArrowItem = new QGraphicsPolygonItem(xArrow);
    xArrowItem->setBrush(Qt::black); // Màu mũi tên
    scene->addItem(xArrowItem);

    // Thêm nhãn cho trục hoành
    QGraphicsTextItem* xAxisLabel = new QGraphicsTextItem("Brand");
    xAxisLabel->setDefaultTextColor(Qt::black); // Màu chữ trắng
    xAxisLabel->setPos(xAxisLength - 100, chartHeight + yOffset + 10); // Đặt nhãn "Brand"
    scene->addItem(xAxisLabel);

    // 9. Thêm tiêu đề cho biểu đồ
    QGraphicsTextItem* title = new QGraphicsTextItem("STATISTICS OF PHONE COMPANIES");
    title->setDefaultTextColor(Qt::red);  // Màu chữ đỏ
    title->setFont(QFont("Arial", 16, QFont::Bold));  // Cỡ chữ và kiểu chữ
    title->setPos((chartWidth / 2) + xOffset - (title->boundingRect().width() / 2), 10);  // Vị trí của tiêu đề
    scene->addItem(title);

    // 10. Hiển thị cảnh (scene) trong QGraphicsView
    ui->graphicsView->setScene(scene);
}


void MainWindow::wheelEvent(QWheelEvent *event) {
    int delta = event->angleDelta().y();

    // Phóng to (scale up) nếu cuộn chuột lên
    if (delta > 0) {
        ui->graphicsView->scale(1.1, 1.1);  // Phóng to 10%
    }
    // Thu nhỏ (scale down) nếu cuộn chuột xuống
    else {
        ui->graphicsView->scale(0.9, 0.9);  // Thu nhỏ 10%
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    // Show graph
    showGraph();

}


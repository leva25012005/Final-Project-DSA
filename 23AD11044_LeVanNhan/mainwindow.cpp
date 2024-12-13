#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "BSTPhone.h"
#include <QMessageBox>
#include <QDebug>
#include <qpainter.h>
#include <QStyleOptionSlider>
#include <QLabel>
#include <QVBoxLayout>


// Hàm hiển thị thành phần của cây
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

    ui->sbPage->hide();
    ui->lbPage->hide();
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
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    // Kết nói sự kiện cho combo box search
    connect(ui->cbSearch_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::cbSearch_2_currentIndexChanged);

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
            ShowPage(ui->treeWidget, filteredNodes, currentPage);
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

}
// Sort
void MainWindow::cbSort_2_currentIndexChanged(int index)
{
    // Chọn loại
    switch(index){
    case 0: // mặc dịnh
        treeRoot = CopyTree(originalTreeRoot); // Khôi phục từ bản sao
        break;
    case 1: // Model a->z
        treeRoot = SortTree(treeRoot, 1 ,true);
        break;
    case 2: // Model z->a
        treeRoot = SortTree(treeRoot, 2, false);
        break;
    case 3: //  price - asc
        treeRoot = SortTree(treeRoot, 4 ,true);
        break;
    case 4: // price -
        treeRoot = SortTree(treeRoot, 4 ,false);
    }

    // Cập nhật lại cây sau khi sắp xếp
    currentPage = 1;
    ui->treeWidget->clear();
    PaginationInWidget(ui->treeWidget, treeRoot);
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
void MainWindow::onChangedIndex() {
    int storageArr[] = {0, 32, 64, 128, 256, 512, 1024};
    int ramArr[] = {0, 2, 3, 4, 6, 8, 12, 16, 24};
    int yearArr[] = {0, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024};

    int storageIndex = ui->cbS->currentIndex();
    int ramIndex = ui->cbR->currentIndex();
    int yearIndex = ui->cbY->currentIndex();

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

    // Cập nhật giao diện với trang đầu tiên
    ShowPage(ui->treeWidget, filteredNodes, currentPage);
}
void MainWindow::btnFilter_clicked()
{
    onChangedIndex();
}

// Search
void MainWindow::onSearchTextChanged(const QString &text) {
    ui->treeWidget->clear(); // Xóa kết quả cũ

    if (text.isEmpty() || ui->cbSearch_2->currentIndex() == 0) {
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
        bool valid = false;
        int id = text.toInt(&valid);

        if (valid) {
            BSTPhone* foundNode = FindNode(treeRoot, id);
            if (foundNode) {
                QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
                item->setText(0, QString::number(foundNode->data.PhoneID));
                item->setText(1, QString::fromStdString(foundNode->data.PhoneBrand));
                item->setText(2, QString::fromStdString(foundNode->data.PhoneModel));
                item->setText(3, QString::fromStdString(foundNode->data.PhoneChipset));
                item->setText(4, QString::fromStdString(foundNode->data.PhoneGPU));
                item->setText(5, QString::number(foundNode->data.PhoneStorage));
                item->setText(6, QString::number(foundNode->data.PhoneRam));
                item->setText(7, QString::number(foundNode->data.PhonePrice));
                item->setText(8, QString::number(foundNode->data.PhoneYear));
            } else {
                QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
                item->setText(0, "Không tìm thấy ID phù hợp");
            }
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
}




#include <QtWidgets>

#include "sorting_algorithm.h"

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        m_table_model = new QStandardItemModel(5, 3, this);
        m_table_view = new QTableView(this);
        m_table_view->setModel(m_table_model);

        QPushButton* sort_button = new QPushButton("Sort", this);
        connect(sort_button, &QPushButton::clicked, this, &MainWindow::on_sort_button_clicked);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(m_table_view);
        layout->addWidget(sort_button);

        QWidget* central_widget = new QWidget(this);
        central_widget->setLayout(layout);
        setCentralWidget(central_widget);
    }

private:
    void on_sort_button_clicked() {
        
        std::vector<int> arr;
        for (int row = 0; row < m_table_model->rowCount(); row++) {
            int value = m_table_model->data(m_table_model->index(row, 0)).toInt();
            arr.push_back(value);
        }

      
        SortingAlgorithm* algorithm = AlgorithmBuilder::build("BubbleSort");
        TimeDecorator time_decorator(algorithm);
        time_decorator.sort(arr);
        delete algorithm;

        
        for (int row = 0; row < m_table_model->rowCount(); row++) {
            int value = arr[row];
            m_table_model->setData(m_table_model->index(row, 0), value);
        }
    }

    QStandardItemModel* m_table_model;
    QTableView* m_table_view;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
#include <QtWidgets>

#include "sorting_algorithm.h"

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        m_table_model = new QStandardItemModel(5, 3, this);
        m_table_view = new QTableView(this);
        m_table_view->setModel(m_table_model);

        QPushButton* sort_button = new QPushButton("Sort", this);
        connect(sort_button, &QPushButton::clicked, this, &MainWindow::on_sort_button_clicked);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(m_table_view);
        layout->addWidget(sort_button);

        QWidget* central_widget = new QWidget(this);
        central_widget->setLayout(layout);
        setCentralWidget(central_widget);
    }

private:
    void on_sort_button_clicked() {
        
        std::vector<int> arr;
        for (int row = 0; row < m_table_model->rowCount(); row++) {
            int value = m_table_model->data(m_table_model->index(row, 0)).toInt();
            arr.push_back(value);
        }

        
        SortingAlgorithm* algorithm = AlgorithmBuilder::build("BubbleSort");
        TimeDecorator time_decorator(algorithm);
        time_decorator.sort(arr);
        delete algorithm;

        
        for (int row = 0; row < m_table_model->rowCount(); row++) {
            int value = arr[row];
            m_table_model->setData(m_table_model->index(row, 0), value);
        }
    }

    QStandardItemModel* m_table_model;
    QTableView* m_table_view;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

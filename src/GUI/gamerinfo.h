#ifndef GAMERINFO_H
#define GAMERINFO_H

#include <QObject>
#include <QWidget>

class GamerInfo : public QWidget
{
    Q_OBJECT
public:
    explicit GamerInfo(QWidget *parent = nullptr);
    ~GamerInfo();
    void setName(QString newName) {name_ = newName;}
    QString getName() const {return name_;}
    void setList(int value) {listToMemorize_.push_back(value);}
    std::vector<int> getList() const {return listToMemorize_;}


private:
    QString name_;
    std::vector<int> listToMemorize_;
    std::vector<int> gamerInput_;
};

#endif // GAMERINFO_H

#ifndef GAMERINFO_H
#define GAMERINFO_H

#include <QObject>
#include <QWidget>

class GamerInfo
{
public:
    explicit GamerInfo();
    ~GamerInfo();

    // getters and setters
    void setName(QString newName) {name_ = newName;}
    QString getName() const {return name_;}
    void addToListUser(int value) {gamerInput_.push_back(value);}
    std::vector<int> getList() const {return listToMemorize_;}
    int getItem(unsigned int index) const {return listToMemorize_[index];}
    unsigned int getNext();
    void generateListInit();
    void generateSingle();
    bool checkEnd();

private:
    QString name_;
    std::vector<int> listToMemorize_;
    std::vector<int> gamerInput_;
    unsigned int iterator_ = 0;
};

#endif // GAMERINFO_H

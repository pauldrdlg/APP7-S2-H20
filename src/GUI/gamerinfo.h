/*
File name: gamerinfo.h
Author: J. LaFerriere
Date: 14-04-2020
Description: Header file for the GamerInfo class, a class where all the back-end/all the user's information is treated
*/

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
	// for user name
    void setName(QString newName) {name_ = newName;}
    QString getName() const {return name_;}

	// for user score
    void increaseScore() {score_ = score_ + 10;}
    int getScore() {return score_;}

	// for lists of sequences (users input and the generated ones)
    const std::vector<int>& getList() const {return listToMemorize_;}
    int getItem(unsigned int index) const {return listToMemorize_[index];}
    void addToListUser(int value) {gamerInput_.push_back(value);}
    const std::vector<int>& getUser() const {return gamerInput_;}
    int getUserItem(unsigned int index) const {return gamerInput_[index];}

	// tools for vectors
    unsigned int getNext();
    void generateListInit();
    void generateSingle();
    bool checkEnd();
    void clearUserInput() {gamerInput_.clear();}
    void clearListMemorize() {listToMemorize_.clear();}

private:
    QString name_;
    int score_ = 0;     // score starts at zero; incremented by 10 for each correct anwser
    std::vector<int> listToMemorize_;
    std::vector<int> gamerInput_;
    unsigned int iterator_ = 0;
};

#endif // GAMERINFO_H

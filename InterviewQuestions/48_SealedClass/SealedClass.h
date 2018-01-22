//
// Created by ChanghuiN on 2018/1/10.
//

// 写一个不能被继承的类
#ifndef EXERCISE_SEALEDCLASS_H
#define EXERCISE_SEALEDCLASS_H


// 私有的构造函数
class SealedClass1 {

public:
    static SealedClass1* GetInstance(){
        return new SealedClass1();
    }
    static void DelectInstance(SealedClass1 pInstance){
        delete pInstance;
    }

private:
    SealedClass1() {};
    ~SealedClass1() {};
};

// 通过虚拟继承
template <typename T> class MakeSealed{
    friend T;

private:
    MakeSealed() {};
    ~MakeSealed() {};
};

class SealedClass2 : virtual MakeSealed<SealedClass2>{
public:
    SealedClass2() {};
    ~SealedClass2() {};
};


#endif //EXERCISE_SEALEDCLASS_H

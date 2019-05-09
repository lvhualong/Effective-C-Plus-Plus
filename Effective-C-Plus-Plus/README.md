# Effective-C-Plus-Plus(Third Edition)

* [01 让自己习惯 C++](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/01%20%E8%AE%A9%E8%87%AA%E5%B7%B1%E4%B9%A0%E6%83%AFC%2B%2B.md)

  + 条款 01：视 C++ 为一个语言联邦
  + 条款 02：尽量以 const，enum，inline，替换 #define
  + 条款 03：尽可能使用 const
  + 条款 04：确定对象被使用前已先被初始化

* [02 构造-析构-赋值运算](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/02%20%E6%9E%84%E9%80%A0-%E6%9E%90%E6%9E%84-%E8%B5%8B%E5%80%BC%E8%BF%90%E7%AE%97.md)

  + 条款 05：了解 C++ 默默编写并调用哪些函数
  + 条款 06：若不想使用编译器自动生成的函数，就该明确拒绝
  + 条款 07：为多态基类声明 virtual 析构函数
  + 条款 08：别让异常逃离析构函数
  + 条款 09：绝不在构造和析构过程中调用 virtual 函数
  + 条款 10：令 operator= 返回一个 reference to `*this`
  + 条款 11：在 operator= 中处理“自我赋值”
  + 条款 12：复制对象时勿忘其每一个成分

* [03 资源管理](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/03%20%E8%B5%84%E6%BA%90%E7%AE%A1%E7%90%86.md)
  
  + 条款 13：以对象管理资源
  + 条款 14：在资源管理类中小心 copying 行为
  + 条款 15：在资源管理类中提供对原始资源的访问
  + 条款 16：成对使用 new 和 delete 时要采取相同形式
  + 条款 17：以独立语句将 newed 对象置入智能指针

* [04 设计与声明](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/04%20%E8%AE%BE%E8%AE%A1%E4%B8%8E%E5%A3%B0%E6%98%8E.md)

  + 条款 18：让接口容易被正确使用，不易被误用
  + 条款 19：设计 class 犹如设计 type
  + 条款 20：宁以 pass-by-reference-to-const 替换 pass-by-value
  + 条款 21：必须返回对象时，别妄想返回其reference
  + 条款 22：将成员变量声明为 private
  + 条款 23：宁以 non-member、non-friend 替换 member 函数
  + 条款 24：若所有参数皆需类型转换，请为此采用 non-member 函数
  + 条款 25：考虑写出一个不抛异常的 swap 函数
  
* [05 实现](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/05%20%E5%AE%9E%E7%8E%B0.md)

  + 条款 26：尽可能延后变量定义式的出现时间
  + 条款 27：尽量少做转型动作
  + 条款 28：避免返回 handles 指向对象内部成分
  + 条款 29：为 “异常安全” 而努力是值得的
  + 条款 30：透彻了解 inlining 的里里外外
  + 条款 31：将文件间的编译依存关系降至最低

* [06 继承与面向对象设计](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/06%20%E7%BB%A7%E6%89%BF%E4%B8%8E%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E8%AE%BE%E8%AE%A1.md)

  + 条款 32：确定你的 public 继承塑模出 is-a 关系
  + 条款 33：避免遮掩继承而来的名称
  + 条款 34：区分接口继承和实现继承
  + 条款 35：考虑 virtual 函数以外的其他选择
  + 条款 36：绝不重新定义继承而来的 non-virtual 函数
  + 条款 37：绝不重新定义继承而来的缺省参数值
  + 条款 38：通过复合塑模出 has-a 或 “根据某物实现出”
  + 条款 39：明智而审慎地使用 private 继承
  + 条款 40：明智而审慎地使用 多重继承

* [07 模板与泛型编程](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/07%20%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B.md)

  + 条款 41：了解隐式接口和编译期多态
  + 条款 42：了解 typename 的双重意义
  + 条款 43：学习处理模板化基类内的名称
  + 条款 44：将与参数无关的代码抽离 template
  + 条款 45：运用成员函数模板接受所有兼容类型
  + 条款 46：需要类型转换时请为模板定义非成员函数 
  + 条款 47：请使用 traits class 表现类型信息
  + 条款 48：认识 template 元编程

* [08 定制 new 和 delete](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/08%20%E5%AE%9A%E5%88%B6%20new%20%E5%92%8C%20delete.md)

  + 条款 49：了解 new-handler 的行为
  + 条款 50：了解 new 和 delete 的合理替换时机
  + 条款 51：编写 new 和 delete 时需固守常规
  + 条款 52：写了 placement new 也要写 placement delete

* [09 杂项讨论](https://github.com/steveLauwh/Effective-C-Plus-Plus/blob/master/09%20%E6%9D%82%E9%A1%B9%E8%AE%A8%E8%AE%BA.md)

  + 条款 53：不要轻忽编译器的警告
  + 条款 54：让自己熟悉包括 TR1 在内的标准程序库
  + 条款 55：让自己熟悉 Boost

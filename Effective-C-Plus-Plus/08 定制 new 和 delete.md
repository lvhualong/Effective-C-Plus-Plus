## 条款49：了解 new-handler 的行为

* STL 容器所使用的 heap 内存是由容器所拥有的分配器对象管理，不是被 new 和 delete 直接管理。
* 设计良好的 new-handler函数必须做以下事情：让更多内存可被使用；安装另一个 new-handler；卸除 new-handler；抛出 bad_alloc的异常；不返回。

```cpp
namespace std {
  typedef void (*new_handler)();
  new_handler set_new_handler(new_handler p) throw();
}
```

* set_new_handler 允许客户指定一个函数，在内存分配无法获得满足时被调用。
* Nothrow new 是一个颇为局限的工具，因为它只适用于内存分配，后继的构造函数调用还是可能抛出异常。

## 条款50：了解 new 和 delete 的合理替换时机

* 有许多理由需要写个自定的 new 和 delete，包括改善效能、对 heap 运用错误进行调试、收集 heap 使用信息。

## 条款51：编写 new 和 delete 时需固守常规

* operator new 应该内含一个无穷循环，并在其中尝试分配内存，如果它无法满足内存需求，就该调用 new-handler。它也应该有能力处理 0
  bytes 申请。Class 专属版本则还应该处理 “比正确大小更大的错误申请”。

```cpp
void* Base::operator new(std::size_t size) throw(std::bad_alloc)
{
  if (size != sizeof(Base))
    return ::operator new(size);
}
```
  
* operator delete 应该在收到 null 指针时不做任何事。Class 专属版本则还应该处理 “比正确大小更大的错误申请”。

```cpp
void Base::operator delete(void* rawMemory, std::size_t size) throw()
{
  if (rawMemory == 0) return;
  
  if (size != sizeof(Base)) {
    ::operator delete(rawMemory);
    return;
  }
  return;
}
```

## 条款52：写了 placement new 也要写 placement delete

* 如果 operator new 接受的参数除了一定会有的那个 size_t 之外还有其他，这便是个所谓的 placement new。
```cpp
void* operator new(std::size_t, void* pMemory) throw();
```
* 如果 operator delete 接受额外的参数，便称为 placement delete。
* 当写一个 placement operator new，请确定也写出 placement operator delete。如果不这样做，程序可能会发生隐微而时断的内存泄漏。
* 当声明 placement new 和 placement delete，请确定不要无意识地遮掩它们的正常版本。

#include <dlfcn.h>
#include <iostream>

typedef int (*func_ptr) ();

using namespace std;

int main()
{
	const char *libso_name = "./hello/libhello.so";

	// �򿪶�̬��
	void *handle = dlopen(libso_name, RTLD_NOW);
	if (handle == NULL) {
		cout << "load " << libso_name << " error: " << dlerror() << endl;
		return -1;
	}

	// �Ӷ�̬���л�ȡ����ָ��
	func_ptr print_hello;
	const char *func_name = "print_hello";
	print_hello = (func_ptr) dlsym(handle, func_name);
	if (print_hello == NULL) {
		cout << "get symbol " << func_name << " error: " << dlerror() << endl;
		return -1;
	}

	int ret = print_hello();

	// �رն�̬��
	dlclose(handle);

	return ret;
}

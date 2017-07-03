#pragma once

template<typename T>
struct DefaultType {
	using type = T;
};


#define MAKE_DEFAULT(i,t) \
	template<> \
	struct DefaultType<i> { \
		using type = t; \
	};

template<typename T, typename... P>
T* GetInstance(P... params) {
	using type = typename DefaultType<T>::type;
	return static_cast<T*>(new type(params...));
}

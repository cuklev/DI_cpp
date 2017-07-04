#pragma once

template<typename T>
struct DefaultType {
	using type = T;
};

template<typename T, typename... P>
inline T* GetInstance(P... params) {
	using type = typename DefaultType<T>::type;
	return static_cast<T*>(new type(params...));
}

#define DEFAULT_INSTANCE(i,t) \
	template<> \
	struct DefaultType<i> { \
		using type = t; \
	};


template<typename T>
T DefaultValue;

template<typename T, typename... TS>
inline T InjectCallValues(T (*f)(TS...)) {
	return f(DefaultValue<TS>...);
}

#define DEFAULT_VALUE(t,v) \
	template<> \
	t DefaultValue = (v);


template<typename T>
T (*FactoryFunc)() = []{
	return T();
};

#define DEFAULT_FACTORY(t,f) \
	template<> \
	t (*FactoryFunc<t>)() = (f);

template<typename T, typename... TS>
inline T InjectCallFactories(T (*f)(TS...)) {
	return f(FactoryFunc<TS>()...);
}

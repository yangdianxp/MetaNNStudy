namespace NSVarTypeDict
{
	template <size_t N, template<typename...> class TCont, typename...T>
	struct Create_ {
		using type = typename Create_<N - 1, TCont, NullParameter, T...>::type;
	};

	template <template<typename...> class TCont, typename...T>
	struct Create_<0, TCont, T...> {
		using type = TCont<T...>;
	};
}

template <typename...TParameters>
struct VarTypeDict
{
	template <typename...TTypes>
	struct Values {
		Values() = default;

		Values(std::shared_ptr<void>(&&input)[sizeof...(TTypes)])
		{
			for (size_t i = 0; i < sizeof...(TTypes); ++i)
			{
				m_tuple[i] = std::move(input[i]);
			}
		}
	public:
		template <typename TTag, typename TVal>
		auto Set(TVal&& val) &&
		{
			using namespace NSMultiTypeDict;
			constexpr static size_t TagPos = Tag2ID<TTag, TParameters...>;

			using rawVAl = std::decay_t<TVal>;
			rawVAl* tmp = new rawVAl(std::forward<Tval>(val));
			m_tuple[TagPos] = std::shared_ptr<void>(tmp,
				[](void* ptr) {
					rawVAl* nptr = static_cast<rawVAl*>(ptr);
					delete nptr;
				});
			
			using new_type = NewTupleType<rawVAl, TagPos, Values<>, TTypes...>;
			return new_type(std::move(m_tuple));
		}

		template <typename TTag>
		const auto& Get() const;

	private:
		std::shared_ptr<void> m_tuple[sizeof...(TTypes)];
	};

public:
	static auto Create() {
		using namespace NSVarTypeDict;
		using type = typename Create_<sizeof...(TParameters),
			Values>::type;
		return type();
	}
};
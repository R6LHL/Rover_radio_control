#ifndef _REGISTER_BASE_HPP
#define _REGISTER_BASE_HPP

template<uint32_t address>
struct RegisterBase
{
	static constexpr auto Addr = address ;
	
	inline static void Set(uint8_t value)
	{
		*reinterpret_cast<volatile uint8_t *>(address) = value ;
	}
  
	//Метод Get возвращает целое значение регистра, 
	inline static uint8_t Get(void)
	{
		return *reinterpret_cast<volatile uint8_t *>(address) ;
	}
  
	static bool GetBit(uint8_t bit_number)
	{
		uint8_t byte_ = *reinterpret_cast<volatile uint8_t *>(address) ;
		uint8_t mask = 0;
		mask = 1 << bit_number;
		byte_ &= mask;
		byte_ >>= (bit_number - 1);
		return byte_;
	}

	static void SetBit (uint8_t bit_number)
	{
		uint8_t byte_ = Get();
		byte_ |= (1<<bit_number);
		Set(byte_);
	}

	static void ClearBit (uint8_t bit_number)
	{
		uint8_t byte_ = Get();
		byte_ &= ~(1<<bit_number);
		Set(byte_);
	}
};

#endif //_REGISTER_BASE_HPP

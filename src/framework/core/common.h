#pragma once

namespace Liver {
	/// Function Pointer
	template<typename T>
	using Func = std::function<T>;

	/// Optional
	template<typename T>
	using Option = std::optional<T>;

	/// Use for owning unique data
	template<typename T>
	using Owned = std::unique_ptr<T>;

	/// Use for owning reference counted data
	template<typename T>
	using Ref = std::shared_ptr<T>;

	/// Use for non-owning references
	template<typename T>
	using Weak = std::weak_ptr<T>;

	// Aliases for fixed types
	// Named similiar to Rust's types.

	/// Alias for an unsigned char
	using byte = unsigned char;
	/// Alias for a int8_t
	using i8 = int8_t;
	/// Alias for a int16_t
	using i16 = int16_t;
	/// Alias for a int32_t
	using i32 = int32_t;
	/// Alias for a int64_t
	using i64 = int64_t;

	/// Alias for a uint8_t
	using u8 = uint8_t;
	/// Alias for a uint16_t
	using u16 = uint16_t;
	/// Alias for a uint32_t
	using u32 = uint32_t;
	/// Alias for a uint64_t
	using u64 = uint64_t;

	/// Alias for a float
	using f32 = float;
	/// Alias for a double
	using f64 = double;
}
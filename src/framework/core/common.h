#pragma once

namespace Sellas {
	// Use for owning unique data
	template<typename T>
	using Owned = std::unique_ptr<T>;

	// Use for owning reference counted data
	template<typename T>
	using Ref = std::shared_ptr<T>;

	// Use for non-owning references
	template<typename T>
	using Weak = std::weak_ptr<T>;

	// Aliases for fixed types
	// Named similiar to Rust's types.
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;

	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	using f32 = float;
	using f64 = double;
}
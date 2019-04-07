///////////////////////////////////////////////////////////
//  ChunkIterator.h
//  Implementation of the classes
//     - Chunk_Chunk_iterator_base
//     - Chunk_Chunk_const_iterator
//     - Chunk_iterator
//  Created on:      26-oct.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(_HEADER_CHUNK_ITERATOR_)
#define _HEADER_CHUNK_ITERATOR_

#include <iterator>

#include "Chunk.h"

class Chunk_iterator_base : public std::iterator<std::random_access_iterator_tag, size_t>
{
public:
	Chunk_iterator_base(class AbsAudioFile& AbsAudioFile, size_t pos = 0);
	Chunk_iterator_base(const Chunk_iterator_base& mdd);

	bool operator==(const Chunk_iterator_base& rhs) const { return equal(rhs); }
	bool operator!=(const Chunk_iterator_base& rhs) const { return !equal(rhs); }

	friend Chunk_iterator_base operator+(const Chunk_iterator_base&, size_t);
	friend iterator operator+(size_t, const iterator&);
	friend Chunk_iterator_base operator-(const Chunk_iterator_base&, size_t);
	friend difference_type operator-(Chunk_iterator_base, Chunk_iterator_base);
	friend void swap(Chunk_iterator_base& lhs, Chunk_iterator_base& rhs);
	friend bool operator==(const Chunk_iterator_base&, const Chunk_iterator_base&);
	friend bool operator!=(const Chunk_iterator_base&, const Chunk_iterator_base&);
	friend bool operator<(const Chunk_iterator_base&, const Chunk_iterator_base&);
	friend bool operator>(const Chunk_iterator_base&, const Chunk_iterator_base&);
	friend bool operator<=(const Chunk_iterator_base&, const Chunk_iterator_base&);
	friend bool operator>=(const Chunk_iterator_base&, const Chunk_iterator_base&);

private:
	class AbsAudioFile& m_audioFile;
	size_t m_chunkIdx;
	Chunk m_currentChunk;

protected:
	void inc(void);
	void dec(void);
	void inc(size_t s);
	void dec(size_t s);
	Chunk& get(void) const;
	Chunk* getp(void) const;
	Chunk& get(size_t pos) const;
	bool equal(const Chunk_iterator_base& rhs) const;
};

// Definition d'un iterateur sur des Chunk constantes
class Chunk_const_iterator : Chunk_iterator_base
{
public:
	Chunk_const_iterator(const class AbsAudioFile& AbsAudioFile, size_t pos = 0) 
		: Chunk_iterator_base(const_cast<class AbsAudioFile&>(AbsAudioFile),pos) {}
	Chunk_const_iterator(const Chunk_const_iterator& mdd) : Chunk_iterator_base(mdd) {}
	Chunk_const_iterator& operator++() { inc(); return *this; }
	Chunk_const_iterator operator++(int) { Chunk_const_iterator tmp(*this); operator++(); return tmp; }
	Chunk_const_iterator& operator--() { dec(); return *this; }
	Chunk_const_iterator operator--(int) { Chunk_const_iterator tmp(*this); operator--(); return tmp; }
	bool operator==(const Chunk_const_iterator& rhs) const { return equal(rhs); }
	bool operator!=(const Chunk_const_iterator& rhs) const { return ! equal(rhs); }
	const Chunk& operator*() const { return get(); }
	const Chunk* operator->() const { return getp(); }
	Chunk_const_iterator& operator+=(size_t s) { inc(s); return *this; }
	Chunk_const_iterator& operator-=(size_t s) { dec(s); return *this; }
	const Chunk& operator[](size_t idx) const { return get(idx); }
};

// Definition d'un iterateur sur des Chunk non-constantes
class Chunk_iterator : Chunk_iterator_base
{
public:
	Chunk_iterator(class AbsAudioFile& AbsAudioFile, size_t pos = 0) : Chunk_iterator_base(AbsAudioFile,pos) {}
	Chunk_iterator(const Chunk_iterator& mdd) : Chunk_iterator_base(mdd) {}
	Chunk_iterator& operator++() { inc(); return *this; }
	Chunk_iterator operator++(int) { Chunk_iterator tmp(*this); operator++(); return tmp; }
	Chunk_iterator& operator--() { dec(); return *this; }
	Chunk_iterator operator--(int) { Chunk_iterator tmp(*this); operator--(); return tmp; }
	bool operator==(const Chunk_iterator& rhs) const { return equal(rhs); }
	bool operator!=(const Chunk_iterator& rhs) const { return !equal(rhs); }
	Chunk& operator*() const { return get(); }
	Chunk* operator->() const { return getp(); }
	Chunk_iterator& operator+=(size_t s) { inc(s); return *this; }
	Chunk_iterator& operator-=(size_t s) { dec(s); return *this; }
	Chunk& operator[](size_t idx) const { return get(idx); }
};

#endif // !defined(_HEADER_CHUNK_ITERATOR_)

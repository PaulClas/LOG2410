#include <iostream>
#include <cstddef>

#include "FileChecksumCalculator.h"
#include "AudioFile.h"
#include "MemAudioFile.h"
#include "ChunkIterator.h"

FileChecksumCalculator * FileChecksumCalculator::clone(void)
{
	return new FileChecksumCalculator(*this);
}

void FileChecksumCalculator::visit(const AudioFile & f)
{
	// Initialiser le checksum avec une valeur non-nulle
	m_checkSum = 0xabcdef00;

	// A COMPLETER:
	// Iterer sur chacun des Chunk
	int i=0;
	for (auto it = f.begin(); it != f.end(); it++) {
		//    - Calculer le hash du Chunk avec computeHash
		//auto hash = computeChunkHash(f.getChunkSize(), it.operator->.get());
		auto hash = computeChunkHash(f.getChunkSize(), it->get());
		//    - Combiner le checksum, le hash du Chunk et l'index du Chunk avec combineHash
		auto combine = combineHash(m_checkSum, hash, i);
		//    - Conserver le resultat comme nouveau checksum
		i++;
	}
}

void FileChecksumCalculator::visit(const MemAudioFile & f)
{
	// Initialiser le checksum avec une valeur non-nulle
	m_checkSum = 0xabcdef00;

	size_t chunkSize = f.getChunkSize();
	size_t nChunks = f.getNumberChunks();
	const char* buf = f.get()+f.getHeaderSize();

	// A COMPLETER:
	// Iterer sur chacun des Chunk
	int i = 0;
	for (auto it = f.begin(); it != f.end(); it++) {
		//    - Calculer le hash du Chunk (portion de buf) avec computeHash
		auto hash = computeChunkHash(chunkSize, it->get());
		//    - Combiner le checksum, le hash du Chunk et l'index du Chunk avec combineHash
		//    - Conserver le resultat comme nouveau checksum
		m_checkSum = combineHash(m_checkSum, hash, i);
		//    - Avancer dans buf
		buf++;
		i++;
	}
}

uint64_t FileChecksumCalculator::computeChunkHash(size_t chunkSize, const char* chunkData)
{
	uint64_t h1 = *(reinterpret_cast<const uint64_t*>(chunkData));
	size_t pieceSize = sizeof(uint64_t);
	size_t nPieces = chunkSize / pieceSize;
	for (size_t iPiece = 1; iPiece < nPieces; ++iPiece)
	{
		uint64_t h2 = *(reinterpret_cast<const uint64_t*>(chunkData+iPiece*pieceSize));
		h2 = h2 << 2*iPiece;
		h1 = combineHash(h1, h2, iPiece);
	}
	return h1;
}

uint64_t FileChecksumCalculator::combineHash(uint64_t h1, uint64_t h2, size_t i)
{
	uint64_t combineh = (h1 & h2) | (~h1 ^ (h2 >> i));
	return combineh;
}

/*	\file   MemoryPool.h
	\author Gregory Diamos <solusstultus@gmail.com>
	\date   November 15, 2012
	\brief  The header file for the MemoryPool class
*/

#pragma once

// Archaeopteryx Includes
#include <archaeopteryx/util/interface/IntTypes.h>
#include <archaeopteryx/util/interface/map.h>
#include <archaeopteryx/util/interface/vector.h>

namespace archaeopteryx
{

namespace rt
{

class MemoryPool
{
public:
	typedef uint64_t Address;

public:
	static const Address InvalidAddress = (Address)(-1);

public:
	__device__ bool allocate(uint64_t size, Address address);
	__device__ Address allocate(Address address);
	__device__ void deallocate(Address address);

	__device__ Address translate(Address address);

private:
	class Page
	{
	public:
		__device__ Page(uint64_t size, Address address);

	public:
		__device__ Address          address() const;
		__device__ Address       endAddress() const;
		__device__ Address  physicalAddress() const;
		__device__ uint64_t            size() const;

	private:
		typedef util::vector<uint8_t> DataVector;

	private:
		Address    _address;
		DataVector _data;	
	};


private:
	typedef util::map<Address, Page> PageMap;

private:
	PageMap _pages;	

};

}

}


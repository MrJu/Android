/*
 * Copyright (C) 2019 Andrew <mrju.email@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 */

#ifndef __DEMO_SERVICE
#define __DEMO_SERVICE

#include <binder/Parcel.h>

using namespace android;

namespace android {

enum {
	CODE_FOO = IBinder::FIRST_CALL_TRANSACTION,
	CODE_BAR,
	CODE_BAZ,
};

class IDemoService : public IInterface
{
public:
	DECLARE_META_INTERFACE(DemoService);

	virtual int doAction(int code)
	{
		return 0;
	}
};

class BpDemoService: public BpInterface<IDemoService>
{
public:
	BpDemoService(const sp<IBinder>& impl);

	virtual int doAction(int code);
};

class BnDemoService: public BnInterface<IDemoService>
{
public:
	virtual status_t onTransact(
			uint32_t code,
			const Parcel& data,
			Parcel* reply, uint32_t flags = 0);
};

}

#endif

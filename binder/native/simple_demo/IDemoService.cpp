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

#include "IDemoService.h"

namespace android
{

IMPLEMENT_META_INTERFACE(DemoService, "android.demo.IDemoService");

BpDemoService::BpDemoService(const sp<IBinder>& impl)
	: BpInterface<IDemoService>(impl)
{
}

int BpDemoService::doAction(int code)
{
	int i;
	Parcel data, reply;

	data.writeInterfaceToken(IDemoService::getInterfaceDescriptor());
	for (i = 0; i < 10; i++)
		data.writeInt32(i);

	remote()->transact(code, data, &reply);

	for (i = 0; i < 10; i++)
		printf("%s %d %d\n",
			__func__, __LINE__, reply.readInt32());

	return 0;
}

status_t BnDemoService::onTransact(uint_t code,
		const Parcel& data, Parcel* reply, uint32_t flags)
{
	int ret, i;

	switch (code) {
	case CODE_FOO:
		CHECK_INTERFACE(IDemoService, data, reply);

		for (i = 0; i < 10; i++)
			reply->writeInt32(data.readInt32() + code);

		break;

	case CODE_BAR:
		CHECK_INTERFACE(IDemoService, data, reply);

		for (i = 0; i < 10; i++)
			reply->writeInt32(data.readInt32() + code);

		break;

	case CODE_BAZ:
		CHECK_INTERFACE(IDemoService, data, reply);

		for (i = 0; i < 10; i++)
			reply->writeInt32(data.readInt32() + code);

		break;

	default:
		return BBinder::onTransact(code, data, reply, flags);
	}

	return NO_ERROR;
}

}

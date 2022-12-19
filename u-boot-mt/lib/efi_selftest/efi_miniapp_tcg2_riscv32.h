/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * This file contains a precompiled EFI binary built from
 * lib/efi_selftest/efi_miniapp_file_image_exit.c and converted to an include
 * using tools/file2include. It is used to testing the EFI_TCG2_PROTOCOL.
 * The precompiled form is needed to avoid the problem of reproducible builds.
 */

#define EFI_ST_DISK_IMG { 0x00001130, { \
	{0x00000000, "\x4d\x5a\x00\x00\x00\x00\x00\x00"}, /* MZ...... */ \
	{0x00000030, "\x52\x49\x53\x43\x56\x00\x00\x00"}, /* RISCV... */ \
	{0x00000038, "\x52\x53\x43\x05\x40\x00\x00\x00"}, /* RSC.@... */ \
	{0x00000040, "\x50\x45\x00\x00\x32\x50\x02\x00"}, /* PE..2P.. */ \
	{0x00000050, "\x00\x00\x00\x00\xe0\x00\x0e\x02"}, /* ........ */ \
	{0x00000058, "\x0b\x01\x02\x14\xb8\x03\x00\x00"}, /* ........ */ \
	{0x00000068, "\x88\x01\x00\x00\x88\x01\x00\x00"}, /* ........ */ \
	{0x00000078, "\x20\x00\x00\x00\x08\x00\x00\x00"}, /*  ....... */ \
	{0x00000080, "\x00\x00\x00\x00\x01\x00\x00\x00"}, /* ........ */ \
	{0x00000090, "\x40\x05\x00\x00\x88\x01\x00\x00"}, /* @....... */ \
	{0x00000098, "\x00\x00\x00\x00\x0a\x00\x00\x00"}, /* ........ */ \
	{0x000000b0, "\x00\x00\x00\x00\x06\x00\x00\x00"}, /* ........ */ \
	{0x00000138, "\x2e\x72\x65\x6c\x6f\x63\x00\x00"}, /* .reloc.. */ \
	{0x00000158, "\x00\x00\x00\x00\x40\x00\x10\x42"}, /* ....@..B */ \
	{0x00000160, "\x2e\x74\x65\x78\x74\x00\x00\x00"}, /* .text... */ \
	{0x00000168, "\xb8\x03\x00\x00\x88\x01\x00\x00"}, /* ........ */ \
	{0x00000170, "\xb8\x03\x00\x00\x88\x01\x00\x00"}, /* ........ */ \
	{0x00000180, "\x00\x00\x00\x00\x20\x00\x50\xe0"}, /* .... .P. */ \
	{0x00000188, "\x51\x11\x2a\xc0\x2e\xc2\x06\xc4"}, /* Q....... */ \
	{0x00000190, "\x17\x05\x00\x00\x13\x05\x05\xe7"}, /* ........ */ \
	{0x00000198, "\x97\x05\x00\x00\x93\x85\x85\x30"}, /* .......0 */ \
	{0x000001a0, "\xe5\x28\x09\xe5\x92\x45\x02\x45"}, /* .(...E.E */ \
	{0x000001a8, "\x9d\x28\xa2\x40\x31\x01\x82\x80"}, /* .(.@1... */ \
	{0x000001b0, "\x01\x11\x22\xcc\x06\xce\x26\xca"}, /* .."...&. */ \
	{0x000001b8, "\xdc\x5d\xc4\x55\x01\x47\x03\xa8"}, /* .].U.G.. */ \
	{0x000001c0, "\x87\x09\x81\x46\x89\x47\x70\x00"}, /* ...F.Gp. */ \
	{0x000001c8, "\x97\x05\x00\x00\x93\x85\x85\x35"}, /* .......5 */ \
	{0x000001d0, "\x02\x98\x2a\x84\x11\xcd\xdc\x40"}, /* .......@ */ \
	{0x000001d8, "\x97\x05\x00\x00\x93\x85\x05\x1a"}, /* ........ */ \
	{0x000001e0, "\x26\x85\x82\x97\xf2\x40\x22\x85"}, /* &....@". */ \
	{0x000001e8, "\x62\x44\xd2\x44\x05\x61\x82\x80"}, /* bD.D.a.. */ \
	{0x000001f0, "\xb2\x46\x17\x07\x00\x00\x13\x07"}, /* .F...... */ \
	{0x000001f8, "\xe7\xfb\x9c\x52\x63\x66\xf7\x00"}, /* ...Rcf.. */ \
	{0x00000200, "\x94\x56\xb6\x97\xe3\x60\xf7\xfe"}, /* .V...`.. */ \
	{0x00000208, "\xdc\x40\x97\x05\x00\x00\x93\x85"}, /* .@...... */ \
	{0x00000210, "\xa5\x1b\x26\x85\x37\x04\x00\x80"}, /* ..&.7... */ \
	{0x00000218, "\x82\x97\x39\x04\xe1\xb7\x79\x71"}, /* ..9...yq */ \
	{0x00000220, "\x06\xd6\x22\xd4\x26\xd2\x4e\xce"}, /* ..".&.N. */ \
	{0x00000228, "\x4a\xd0\x03\xa9\xc5\x02\x8a\x89"}, /* J....... */ \
	{0x00000230, "\xaa\x84\x2e\x84\x41\x46\x97\x05"}, /* ....AF.. */ \
	{0x00000238, "\x00\x00\x93\x85\x25\x25\x4e\x85"}, /* ....%%N. */ \
	{0x00000240, "\x39\x2a\x83\x27\x49\x00\x97\x05"}, /* 9..'I... */ \
	{0x00000248, "\x00\x00\x93\x85\x65\x1c\x4a\x85"}, /* ....e.J. */ \
	{0x00000250, "\x82\x97\xa2\x85\x26\x85\xa9\x3f"}, /* ....&..? */ \
	{0x00000258, "\x1d\xc9\x83\x27\x49\x00\x97\x05"}, /* ...'I... */ \
	{0x00000260, "\x00\x00\x93\x85\xa5\x1e\x4a\x85"}, /* ......J. */ \
	{0x00000268, "\x82\x97\xb7\x07\x00\x80\x93\x85"}, /* ........ */ \
	{0x00000270, "\xe7\x00\x5c\x5c\xce\x86\x26\x85"}, /* ..\\..&. */ \
	{0x00000278, "\xbc\x5f\x41\x46\x82\x97\xb2\x50"}, /* ._AF...P */ \
	{0x00000280, "\x22\x54\x92\x54\x02\x59\xf2\x49"}, /* "T.T.Y.I */ \
	{0x00000288, "\x01\x45\x45\x61\x82\x80\xb7\x07"}, /* .EEa.... */ \
	{0x00000290, "\x00\x80\x93\x85\x37\x00\xf1\xbf"}, /* ....7... */ \
	{0x00000298, "\x81\x47\x01\x47\x81\x46\x21\x48"}, /* .G.G.F!H */ \
	{0x000002a0, "\xa5\x48\x1d\x43\x90\x41\x09\xe6"}, /* .H.C.A.. */ \
	{0x000002a8, "\x95\xe3\x1d\xe3\x01\x45\x82\x80"}, /* .....E.. */ \
	{0x000002b0, "\x63\x0a\x06\x01\x63\x0a\x16\x01"}, /* c...c... */ \
	{0x000002b8, "\x63\x14\x66\x00\xdc\x41\xaa\x97"}, /* c.f..A.. */ \
	{0x000002c0, "\xa1\x05\xcd\xb7\xd4\x41\xed\xbf"}, /* .....A.. */ \
	{0x000002c8, "\xd8\x41\xdd\xbf\x0d\x48\x05\xe3"}, /* .A...H.. */ \
	{0x000002d0, "\x37\x05\x00\x80\x05\x05\x82\x80"}, /* 7....... */ \
	{0x000002d8, "\x03\xc6\x47\x00\x63\x1c\x06\x01"}, /* ..G.c... */ \
	{0x000002e0, "\x90\x43\x8c\x47\x99\x8e\x2a\x96"}, /* .C.G.... */ \
	{0x000002e8, "\xaa\x95\x0c\xc2\xba\x97\xe3\x45"}, /* .......E */ \
	{0x000002f0, "\xd0\xfe\x6d\xbf\x01\xa0\x01\x47"}, /* ..m....G */ \
	{0x000002f8, "\x63\x14\xe6\x00\x01\x45\x82\x80"}, /* c....E.. */ \
	{0x00000300, "\xb3\x07\xe5\x00\x05\x07\xb3\x86"}, /* ........ */ \
	{0x00000308, "\xe5\x00\x83\xc7\x07\x00\x83\xc6"}, /* ........ */ \
	{0x00000310, "\xf6\xff\xe3\x83\xd7\xfe\x33\x85"}, /* ......3. */ \
	{0x00000318, "\xd7\x40\x82\x80\x63\xf5\xa5\x02"}, /* .@..c... */ \
	{0x00000320, "\x93\x46\xf6\xff\x81\x47\xfd\x17"}, /* .F...G.. */ \
	{0x00000328, "\x63\x91\xd7\x02\x82\x80\x33\x87"}, /* c.....3. */ \
	{0x00000330, "\xf5\x00\x83\x46\x07\x00\x33\x07"}, /* ...F..3. */ \
	{0x00000338, "\xf5\x00\x85\x07\x23\x00\xd7\x00"}, /* ....#... */ \
	{0x00000340, "\xe3\x97\xc7\xfe\x82\x80\x81\x47"}, /* .......G */ \
	{0x00000348, "\xe5\xbf\x33\x07\xf6\x00\x33\x88"}, /* ..3...3. */ \
	{0x00000350, "\xe5\x00\x03\x48\x08\x00\x2a\x97"}, /* ...H.... */ \
	{0x00000358, "\x23\x00\x07\x01\xe9\xb7\x7d\xbf"}, /* #.....}. */ \
	{0x00000360, "\x2a\x96\xaa\x87\x63\x93\xc7\x00"}, /* ....c... */ \
	{0x00000368, "\x82\x80\x85\x07\xa3\x8f\xb7\xfe"}, /* ........ */ \
	{0x00000370, "\xd5\xbf\x82\x80\x82\x80\x00\x00"}, /* ........ */ \
	{0x00000378, "\x43\x00\x6f\x00\x75\x00\x6c\x00"}, /* C.o.u.l. */ \
	{0x00000380, "\x64\x00\x20\x00\x6e\x00\x6f\x00"}, /* d. .n.o. */ \
	{0x00000388, "\x74\x00\x20\x00\x6f\x00\x70\x00"}, /* t. .o.p. */ \
	{0x00000390, "\x65\x00\x6e\x00\x20\x00\x6c\x00"}, /* e.n. .l. */ \
	{0x00000398, "\x6f\x00\x61\x00\x64\x00\x65\x00"}, /* o.a.d.e. */ \
	{0x000003a0, "\x64\x00\x20\x00\x69\x00\x6d\x00"}, /* d. .i.m. */ \
	{0x000003a8, "\x61\x00\x67\x00\x65\x00\x20\x00"}, /* a.g.e. . */ \
	{0x000003b0, "\x70\x00\x72\x00\x6f\x00\x74\x00"}, /* p.r.o.t. */ \
	{0x000003b8, "\x6f\x00\x63\x00\x6f\x00\x6c\x00"}, /* o.c.o.l. */ \
	{0x000003c0, "\x00\x00\x00\x00\x49\x00\x6e\x00"}, /* ....I.n. */ \
	{0x000003c8, "\x63\x00\x6f\x00\x72\x00\x72\x00"}, /* c.o.r.r. */ \
	{0x000003d0, "\x65\x00\x63\x00\x74\x00\x20\x00"}, /* e.c.t. . */ \
	{0x000003d8, "\x69\x00\x6d\x00\x61\x00\x67\x00"}, /* i.m.a.g. */ \
	{0x000003e0, "\x65\x00\x5f\x00\x62\x00\x61\x00"}, /* e._.b.a. */ \
	{0x000003e8, "\x73\x00\x65\x00\x20\x00\x6f\x00"}, /* s.e. .o. */ \
	{0x000003f0, "\x72\x00\x20\x00\x69\x00\x6d\x00"}, /* r. .i.m. */ \
	{0x000003f8, "\x61\x00\x67\x00\x65\x00\x5f\x00"}, /* a.g.e._. */ \
	{0x00000400, "\x73\x00\x69\x00\x7a\x00\x65\x00"}, /* s.i.z.e. */ \
	{0x00000408, "\x0a\x00\x00\x00\x45\x00\x46\x00"}, /* ....E.F. */ \
	{0x00000410, "\x49\x00\x20\x00\x61\x00\x70\x00"}, /* I. .a.p. */ \
	{0x00000418, "\x70\x00\x6c\x00\x69\x00\x63\x00"}, /* p.l.i.c. */ \
	{0x00000420, "\x61\x00\x74\x00\x69\x00\x6f\x00"}, /* a.t.i.o. */ \
	{0x00000428, "\x6e\x00\x20\x00\x63\x00\x61\x00"}, /* n. .c.a. */ \
	{0x00000430, "\x6c\x00\x6c\x00\x69\x00\x6e\x00"}, /* l.l.i.n. */ \
	{0x00000438, "\x67\x00\x20\x00\x45\x00\x78\x00"}, /* g. .E.x. */ \
	{0x00000440, "\x69\x00\x74\x00\x0a\x00\x00\x00"}, /* i.t..... */ \
	{0x00000448, "\x4c\x00\x6f\x00\x61\x00\x64\x00"}, /* L.o.a.d. */ \
	{0x00000450, "\x65\x00\x64\x00\x20\x00\x69\x00"}, /* e.d. .i. */ \
	{0x00000458, "\x6d\x00\x61\x00\x67\x00\x65\x00"}, /* m.a.g.e. */ \
	{0x00000460, "\x20\x00\x70\x00\x72\x00\x6f\x00"}, /*  .p.r.o. */ \
	{0x00000468, "\x74\x00\x6f\x00\x63\x00\x6f\x00"}, /* t.o.c.o. */ \
	{0x00000470, "\x6c\x00\x20\x00\x6d\x00\x69\x00"}, /* l. .m.i. */ \
	{0x00000478, "\x73\x00\x73\x00\x69\x00\x6e\x00"}, /* s.s.i.n. */ \
	{0x00000480, "\x67\x00\x0a\x00\x00\x00\x00\x00"}, /* g....... */ \
	{0x00000488, "\x53\x00\x55\x00\x43\x00\x43\x00"}, /* S.U.C.C. */ \
	{0x00000490, "\x45\x00\x53\x00\x53\x00\x00\x00"}, /* E.S.S... */ \
	{0x000004a0, "\x10\x00\x00\x00\x00\x00\x00\x00"}, /* ........ */ \
	{0x000004a8, "\x04\x00\x00\x00\xac\x20\x00\x00"}, /* ..... .. */ \
	{0x000004b0, "\xf5\xfe\xff\x6f\x44\x21\x00\x00"}, /* ...oD!.. */ \
	{0x000004b8, "\x05\x00\x00\x00\x00\x20\x00\x00"}, /* ..... .. */ \
	{0x000004c0, "\x06\x00\x00\x00\x00\x10\x00\x00"}, /* ........ */ \
	{0x000004c8, "\x0a\x00\x00\x00\xaa\x00\x00\x00"}, /* ........ */ \
	{0x000004d0, "\x0b\x00\x00\x00\x10\x00\x00\x00"}, /* ........ */ \
	{0x000004d8, "\x07\x00\x00\x00\x00\x00\x00\x00"}, /* ........ */ \
	{0x000004e0, "\x08\x00\x00\x00\x00\x00\x00\x00"}, /* ........ */ \
	{0x000004e8, "\x09\x00\x00\x00\x0c\x00\x00\x00"}, /* ........ */ \
	{0x00000520, "\xa1\x31\x1b\x5b\x62\x95\xd2\x11"}, /* .1.[b... */ \
	{0x00000528, "\x8e\x3f\x00\xa0\xc9\x69\x72\x3b"}, /* .?...ir; */ \
	{0x00000530, "\xa0\x04\x00\x00\x00\x00\x00\x00"}, /* ........ */ \
	{0x00001018, "\x00\x00\x00\x00\x03\x00\x01\x00"}, /* ........ */ \
	{0x00001020, "\x42\x00\x00\x00\x72\x03\x00\x00"}, /* B...r... */ \
	{0x00001028, "\x02\x00\x00\x00\x12\x00\x01\x00"}, /* ........ */ \
	{0x00001030, "\x73\x00\x00\x00\x00\x00\x00\x00"}, /* s....... */ \
	{0x00001038, "\x00\x00\x00\x00\x10\x00\x01\x00"}, /* ........ */ \
	{0x00001040, "\x3b\x00\x00\x00\x60\x03\x00\x00"}, /* ;...`... */ \
	{0x00001048, "\x12\x00\x00\x00\x12\x00\x01\x00"}, /* ........ */ \
	{0x00001050, "\x96\x00\x00\x00\x40\x05\x00\x00"}, /* ....@... */ \
	{0x00001058, "\x00\x00\x00\x00\x10\x00\x03\x00"}, /* ........ */ \
	{0x00001060, "\x22\x00\x00\x00\x98\x02\x00\x00"}, /* "....... */ \
	{0x00001068, "\x5e\x00\x00\x00\x12\x00\x01\x00"}, /* ^....... */ \
	{0x00001070, "\x2c\x00\x00\x00\xf6\x02\x00\x00"}, /* ,....... */ \
	{0x00001078, "\x26\x00\x00\x00\x12\x00\x01\x00"}, /* &....... */ \
	{0x00001080, "\x1b\x00\x00\x00\x40\x05\x00\x00"}, /* ....@... */ \
	{0x00001088, "\x00\x00\x00\x00\x10\x00\x03\x00"}, /* ........ */ \
	{0x00001090, "\x5b\x00\x00\x00\x74\x03\x00\x00"}, /* [...t... */ \
	{0x00001098, "\x02\x00\x00\x00\x12\x00\x01\x00"}, /* ........ */ \
	{0x000010a0, "\x9f\x00\x00\x00\xa0\x00\x00\x00"}, /* ........ */ \
	{0x000010a8, "\x00\x00\x00\x00\x10\x00\x03\x00"}, /* ........ */ \
	{0x000010b0, "\x79\x00\x00\x00\xa0\x04\x00\x00"}, /* y....... */ \
	{0x000010b8, "\x00\x00\x00\x00\x10\x00\x01\x00"}, /* ........ */ \
	{0x000010c0, "\x33\x00\x00\x00\x1c\x03\x00\x00"}, /* 3....... */ \
	{0x000010c8, "\x42\x00\x00\x00\x12\x00\x01\x00"}, /* B....... */ \
	{0x000010d0, "\x01\x00\x00\x00\x1e\x02\x00\x00"}, /* ........ */ \
	{0x000010d8, "\x7a\x00\x00\x00\x12\x00\x01\x00"}, /* z....... */ \
	{0x000010e0, "\x91\x00\x00\x00\x40\x05\x00\x00"}, /* ....@... */ \
	{0x000010e8, "\x00\x00\x00\x00\x10\x00\x03\x00"}, /* ........ */ \
	{0x000010f0, "\x11\x00\x00\x00\x00\x00\x00\x00"}, /* ........ */ \
	{0x000010f8, "\x00\x00\x00\x00\x10\x00\x01\x00"}, /* ........ */ \
	{0x00001100, "\x80\x00\x00\x00\xa0\x04\x00\x00"}, /* ........ */ \
	{0x00001108, "\x00\x00\x00\x00\x10\x00\xf1\xff"}, /* ........ */ \
	{0x00001110, "\x0a\x00\x00\x00\x5e\x03\x00\x00"}, /* ....^... */ \
	{0x00001118, "\x02\x00\x00\x00\x12\x00\x01\x00"}, /* ........ */ \
	{0x00001120, "\x8b\x00\x00\x00\x20\x05\x00\x00"}, /* .... ... */ \
	{0x00001128, "\x00\x00\x00\x00\x10\x00\x03\x00"}, /* ........ */ \
	{0, NULL} } }

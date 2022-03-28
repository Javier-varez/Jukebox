/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FailSound.h
 * Brief: Sound for Failure
 * Module: Sound
 */

#ifndef ATE_OK_SOUND_H_
#define ATE_OK_SOUND_H_

namespace ATE::Audio::Sound
{
    constexpr unsigned char Ok_mp3[] = {
      0xff, 0xfb, 0x54, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x49, 0x6e, 0x66, 0x6f, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10,
      0x00, 0x00, 0x0c, 0xc0, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20,
      0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50,
      0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
      0x90, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0,
      0xb0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0,
      0xd0, 0xd0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0,
      0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x39,
      0x4c, 0x41, 0x4d, 0x45, 0x33, 0x2e, 0x31, 0x30, 0x30, 0x01, 0x6e, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x40, 0x24, 0x02, 0x40,
      0x8e, 0x00, 0x00, 0x40, 0x00, 0x00, 0x0c, 0xc0, 0x50, 0x1e, 0x5f, 0x17,
      0xff, 0xfb, 0x54, 0x64, 0x00, 0x0f, 0xf1, 0x37, 0x40, 0xbc, 0x80, 0x20,
      0x1c, 0xc2, 0x12, 0x87, 0x57, 0xc0, 0x00, 0x22, 0xe4, 0x43, 0x29, 0x0f,
      0x04, 0x00, 0x04, 0x7c, 0x40, 0x71, 0x20, 0xe0, 0x40, 0x00, 0x8f, 0x89,
      0xff, 0xff, 0xf8, 0x00, 0xbf, 0xff, 0x10, 0xff, 0x4e, 0xbf, 0xa2, 0x16,
      0xfa, 0x12, 0x15, 0x7d, 0x34, 0x10, 0x69, 0x40, 0xc0, 0xcc, 0x22, 0xbe,
      0x95, 0xc2, 0x08, 0x73, 0x47, 0x70, 0xe6, 0x88, 0x00, 0x00, 0x48, 0x21,
      0x08, 0x87, 0xad, 0xff, 0xcb, 0xff, 0x90, 0x17, 0xfc, 0x00, 0xf3, 0x19,
      0x81, 0x78, 0xc3, 0x8b, 0x00, 0x8e, 0x3c, 0x40, 0x63, 0x3f, 0xef, 0xfd,
      0xb9, 0xc1, 0x69, 0x9e, 0xfe, 0x6d, 0x6c, 0xe3, 0x83, 0xcb, 0x58, 0x75,
      0x5a, 0x1e, 0x8d, 0x10, 0x5b, 0xa3, 0x2c, 0x0e, 0xa6, 0xa3, 0x97, 0xfe,
      0x59, 0x1e, 0xf6, 0xd3, 0x99, 0x47, 0xc1, 0xa5, 0x77, 0x58, 0xb8, 0x76,
      0x2b, 0x92, 0xa1, 0x29, 0x4d, 0x42, 0xf6, 0x0b, 0x0a, 0x00, 0x76, 0x8b,
      0x32, 0xd3, 0xce, 0x32, 0xcb, 0x20, 0x20, 0x2c, 0x08, 0x05, 0x14, 0xb1,
      0xc0, 0x94, 0x94, 0xde, 0x9e, 0x15, 0x7c, 0xb7, 0x1c, 0xbd, 0x80, 0x0e,
      0x26, 0x85, 0x84, 0x18, 0x60, 0x47, 0xd4, 0xec, 0x81, 0xf8, 0x38, 0xb2,
      0x10, 0x7d, 0xd6, 0x8b, 0x1c, 0x53, 0x76, 0x10, 0xe6, 0x9a, 0xd8, 0x3f,
      0xff, 0xfb, 0x54, 0x64, 0x16, 0x81, 0x51, 0x7d, 0x16, 0xc5, 0x60, 0x21,
      0x18, 0x70, 0x30, 0x44, 0x08, 0x9b, 0x04, 0xc2, 0x92, 0x05, 0x88, 0x9b,
      0x22, 0xb4, 0x31, 0x80, 0x00, 0xba, 0x12, 0x63, 0xc2, 0x82, 0x30, 0x00,
      0xca, 0x17, 0x79, 0x8a, 0x34, 0x00, 0x03, 0x00, 0xb7, 0x1c, 0x8e, 0xec,
      0xdf, 0x7b, 0x01, 0xb9, 0x88, 0x7f, 0x76, 0xdf, 0x98, 0x10, 0x90, 0x63,
      0x92, 0x81, 0x04, 0x37, 0xfe, 0x4b, 0xe7, 0x0e, 0x20, 0xb9, 0xf9, 0x73,
      0x81, 0x8c, 0x32, 0xef, 0xef, 0x58, 0x59, 0x4e, 0x8e, 0xa4, 0x67, 0x78,
      0xe4, 0x86, 0x14, 0x02, 0x7e, 0x4e, 0x1c, 0x0c, 0xff, 0x47, 0x7c, 0xb8,
      0x21, 0x00, 0x0c, 0xac, 0x49, 0xca, 0x74, 0xe4, 0x4d, 0xcf, 0xc0, 0x12,
      0x27, 0x93, 0xa1, 0x7d, 0x73, 0xcf, 0xcb, 0x3f, 0xa4, 0x68, 0x5b, 0xbb,
      0xe1, 0x3c, 0x59, 0xd6, 0xe5, 0xa9, 0x4e, 0x82, 0x16, 0x51, 0xc6, 0x88,
      0x07, 0xfe, 0x03, 0x91, 0x01, 0x13, 0xb5, 0x0f, 0x74, 0xa5, 0xb2, 0x57,
      0x78, 0x82, 0xaa, 0x4e, 0x9c, 0xa8, 0x47, 0xee, 0xe6, 0xe5, 0xe8, 0x89,
      0xea, 0x40, 0xb9, 0xe4, 0x1c, 0x5e, 0x57, 0x53, 0xeb, 0x07, 0x30, 0x40,
      0x10, 0x0d, 0x9c, 0x2f, 0xc7, 0x7f, 0xb0, 0x3e, 0xe0, 0xc5, 0xb5, 0x5a,
      0xed, 0x82, 0xcb, 0x58, 0xae, 0xd8, 0x2a, 0xb5, 0x0a, 0x00, 0x00, 0x07,
      0xff, 0xfb, 0x54, 0x64, 0x07, 0x00, 0x01, 0x77, 0x0c, 0x58, 0xee, 0x18,
      0x40, 0x04, 0x22, 0x60, 0x0a, 0x59, 0xc0, 0x88, 0x00, 0x05, 0xc8, 0x75,
      0x56, 0x18, 0x63, 0x00, 0x00, 0x71, 0x00, 0x6a, 0x57, 0x00, 0x30, 0x00,
      0xd6, 0x83, 0xc9, 0xf7, 0xc6, 0x4c, 0x23, 0x5b, 0xe8, 0x46, 0x75, 0x16,
      0x09, 0xae, 0x68, 0x27, 0xb1, 0xe0, 0xfa, 0x69, 0x3f, 0x02, 0x24, 0xe7,
      0x5a, 0xf7, 0xa5, 0x3b, 0xd8, 0x75, 0x46, 0x7f, 0xdf, 0xe0, 0x27, 0xfe,
      0x61, 0x81, 0x98, 0x00, 0x00, 0x00, 0xe7, 0x70, 0x3d, 0xe4, 0x5e, 0x38,
      0xe5, 0x48, 0x01, 0xec, 0x78, 0x3f, 0xf7, 0xad, 0xbd, 0x07, 0x65, 0xc3,
      0xe7, 0x3f, 0xc9, 0x9c, 0xff, 0x29, 0x52, 0x11, 0x64, 0xe4, 0x35, 0x9f,
      0xa5, 0xd2, 0x9f, 0xeb, 0x20, 0x63, 0xcf, 0x40, 0x3b, 0x64, 0xdd, 0xb6,
      0xfc, 0xc7, 0xc8, 0xd3, 0xe7, 0x97, 0x71, 0xb9, 0xfe, 0xb3, 0xe7, 0x76,
      0x9d, 0xd2, 0x98, 0xc8, 0x51, 0x05, 0xda, 0x22, 0x8d, 0xa9, 0xf6, 0x5b,
      0x71, 0xb7, 0x8a, 0xa2, 0xee, 0xa1, 0xd0, 0xf0, 0x00, 0x00, 0xd4, 0xa2,
      0x9b, 0x9e, 0x3f, 0x18, 0xa3, 0x0b, 0x53, 0x9f, 0x8c, 0x74, 0xec, 0x0e,
      0x8f, 0xd2, 0xe5, 0x4b, 0x74, 0xfd, 0xca, 0xa7, 0xd5, 0xa1, 0x5d, 0x4c,
      0x50, 0x23, 0x57, 0x4e, 0x56, 0x16, 0x3d, 0xe0, 0xdc, 0x80, 0xfa, 0x35,
      0xff, 0xfb, 0x54, 0x64, 0x07, 0x00, 0x01, 0xb2, 0x2f, 0x59, 0x06, 0x41,
      0x40, 0x00, 0x1d, 0x40, 0xfb, 0xfd, 0xc1, 0x08, 0x00, 0x86, 0x08, 0x89,
      0x7c, 0x18, 0x91, 0x80, 0x00, 0x6c, 0x80, 0x32, 0xf7, 0x04, 0x00, 0x02,
      0x90, 0x57, 0x03, 0x1a, 0xb3, 0x43, 0xe0, 0x20, 0x45, 0xf7, 0x61, 0xa0,
      0xff, 0xff, 0x72, 0xa3, 0xe0, 0xbc, 0x1d, 0xff, 0xf2, 0x81, 0x78, 0x24,
      0x0e, 0x18, 0x24, 0x7f, 0x5f, 0x78, 0xa0, 0x7e, 0x62, 0x93, 0x89, 0xff,
      0xc1, 0xf7, 0xff, 0xfb, 0xbf, 0x62, 0x0d, 0x40, 0x0c, 0x50, 0x00, 0x00,
      0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x04, 0x14, 0x8d, 0xc0, 0xf6,
      0x8b, 0xeb, 0x74, 0x3c, 0x73, 0xff, 0xff, 0xfe, 0x5e, 0xae, 0xfe, 0xc5,
      0x2a, 0x98, 0x7c, 0xa0, 0x2f, 0x30, 0x7c, 0x48, 0x7a, 0x06, 0xc5, 0xc5,
      0x40, 0xc1, 0x34, 0x16, 0x86, 0x47, 0x48, 0x48, 0xcd, 0x12, 0x9c, 0xcc,
      0x8f, 0xec, 0x22, 0x3e, 0x59, 0xf4, 0xe0, 0xb2, 0xcc, 0x26, 0x34, 0xf1,
      0x61, 0x57, 0xbc, 0x2e, 0xab, 0xcf, 0xb5, 0x25, 0xff, 0xaf, 0x80, 0x03,
      0x01, 0x08, 0x24, 0x80, 0x00, 0x20, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x01,
      0x4f, 0x56, 0x88, 0x21, 0x48, 0x45, 0x8a, 0x3d, 0xff, 0x92, 0x7e, 0xba,
      0x92, 0x93, 0x22, 0x20, 0x20, 0x12, 0x10, 0x41, 0xc0, 0xbb, 0x75, 0x9b,
      0xff, 0xfb, 0x54, 0x64, 0x05, 0x80, 0x11, 0xb4, 0x10, 0xde, 0x77, 0x3c,
      0xc0, 0x00, 0x18, 0xc0, 0x3c, 0x8e, 0xe4, 0x0c, 0x01, 0x86, 0x8c, 0x47,
      0x77, 0xc6, 0x18, 0x6c, 0x48, 0x5e, 0x00, 0xaf, 0xb8, 0x20, 0x8c, 0x04,
      0x90, 0xbf, 0x05, 0x4a, 0x74, 0x4b, 0x04, 0x72, 0x90, 0xe5, 0xba, 0xae,
      0x55, 0x93, 0x34, 0x9d, 0x9b, 0xa3, 0x69, 0x9d, 0xa2, 0x25, 0x00, 0xf8,
      0xea, 0x1e, 0x3e, 0x3c, 0x80, 0x8c, 0xca, 0xc2, 0x87, 0xbd, 0xc8, 0x60,
      0xf1, 0x5b, 0x07, 0x8d, 0xab, 0x2e, 0x36, 0xfa, 0x40, 0x55, 0x32, 0x04,
      0x40, 0xb0, 0x08, 0x02, 0x40, 0xfd, 0xb0, 0xe4, 0x97, 0x70, 0xb3, 0x35,
      0x2e, 0x41, 0xf6, 0x33, 0xff, 0xff, 0xfe, 0xaa, 0xee, 0x49, 0x40, 0x00,
      0x0c, 0x80, 0x40, 0x80, 0x1c, 0x26, 0xa1, 0x09, 0xa2, 0x15, 0x65, 0x91,
      0xce, 0x2c, 0x2a, 0x81, 0x14, 0x76, 0x2f, 0x0d, 0x19, 0x6c, 0xa8, 0x6c,
      0x1a, 0xdd, 0x83, 0xd6, 0x81, 0x84, 0xe4, 0x7f, 0x6d, 0xfb, 0xaa, 0x25,
      0x20, 0x9d, 0xef, 0xf7, 0xfe, 0xfc, 0xc2, 0xc5, 0x4f, 0xa7, 0xe1, 0x1b,
      0x9f, 0x00, 0x00, 0x00, 0x1a, 0x18, 0x06, 0x0e, 0x17, 0xe8, 0x53, 0x0a,
      0x99, 0x13, 0xff, 0xe7, 0x96, 0x7a, 0xff, 0xff, 0xdf, 0x5f, 0x52, 0x35,
      0x55, 0xf0, 0xd3, 0x12, 0x44, 0x84, 0x4a, 0x4f, 0x00, 0x3d, 0x07, 0x38,
      0xff, 0xfb, 0x54, 0x64, 0x05, 0x80, 0x01, 0xae, 0x09, 0xe0, 0x69, 0x8c,
      0x31, 0x24, 0x18, 0x40, 0x5b, 0xbe, 0x01, 0x01, 0x00, 0x06, 0xbc, 0x59,
      0x85, 0xe7, 0xb1, 0x04, 0xb0, 0x65, 0x81, 0x31, 0x7c, 0x62, 0x84, 0x06,
      0x41, 0x1a, 0xdf, 0x30, 0x1a, 0x46, 0x93, 0x51, 0x10, 0x15, 0x18, 0x16,
      0x9b, 0xd0, 0x32, 0x34, 0x1f, 0x11, 0x19, 0x02, 0x80, 0xe5, 0x01, 0xf2,
      0xcd, 0x66, 0xb5, 0x05, 0x03, 0x63, 0xdd, 0xbf, 0xad, 0x80, 0x9a, 0x22,
      0xe9, 0x2e, 0x9d, 0xa9, 0xb3, 0xfc, 0x54, 0x29, 0x4c, 0x00, 0x0c, 0xcc,
      0x04, 0x08, 0x01, 0xc0, 0xc6, 0xf6, 0x9f, 0xb8, 0x6a, 0xd2, 0x35, 0xbf,
      0x21, 0xfe, 0xcf, 0xfe, 0xa2, 0xb3, 0xea, 0x86, 0x26, 0x02, 0x33, 0x44,
      0x30, 0xc8, 0x01, 0x40, 0x1e, 0x99, 0x6e, 0x8e, 0x33, 0x90, 0xaf, 0x06,
      0x05, 0x6d, 0x2d, 0x20, 0x42, 0x10, 0xb9, 0xa7, 0x54, 0xb5, 0xd4, 0xc2,
      0x87, 0x17, 0xc5, 0x91, 0xea, 0xb5, 0x74, 0xd6, 0x54, 0x5c, 0x9a, 0xe8,
      0xcd, 0xf4, 0xf5, 0xab, 0xaf, 0x48, 0xbf, 0xac, 0x2d, 0x87, 0x7f, 0x80,
      0xdd, 0x2e, 0x08, 0x00, 0x80, 0xc8, 0x88, 0x00, 0x02, 0x80, 0x0f, 0x98,
      0x4a, 0xbc, 0x0b, 0x81, 0x6b, 0x6d, 0x09, 0x6f, 0xff, 0xff, 0xff, 0xfb,
      0x7f, 0xe5, 0x95, 0xc3, 0x08, 0x00, 0x46, 0x64, 0x71, 0x59, 0xc0, 0x3b,
      0xff, 0xfb, 0x54, 0x64, 0x04, 0x80, 0x11, 0xa5, 0x11, 0xdd, 0x71, 0xe9,
      0x11, 0xb8, 0x16, 0x40, 0x1c, 0x3e, 0x08, 0x22, 0x01, 0x86, 0xe8, 0x77,
      0x63, 0xa7, 0xb0, 0x45, 0x00, 0x60, 0x8e, 0xab, 0x00, 0x20, 0x09, 0xc8,
      0xd6, 0xb2, 0xd8, 0x20, 0x8b, 0x46, 0x9a, 0x9a, 0x80, 0x09, 0x9a, 0x26,
      0xc1, 0x53, 0x4e, 0x66, 0x52, 0x60, 0x85, 0x06, 0x39, 0x85, 0xfa, 0x0a,
      0x90, 0xab, 0x2a, 0xe1, 0x33, 0xca, 0x04, 0x9a, 0xbd, 0xc5, 0xb3, 0x2e,
      0x14, 0x01, 0x05, 0x41, 0xc3, 0xdc, 0x58, 0xb4, 0x81, 0x00, 0x02, 0x23,
      0x32, 0x99, 0x80, 0x00, 0xee, 0x5f, 0x55, 0xc5, 0x99, 0x01, 0x24, 0x59,
      0x9c, 0xcf, 0xf0, 0xe2, 0x09, 0x53, 0x50, 0x6c, 0x06, 0x98, 0x05, 0x34,
      0x70, 0x03, 0x4e, 0xa3, 0xa8, 0x00, 0x1d, 0x97, 0x01, 0x94, 0x28, 0x04,
      0xa3, 0x44, 0xc5, 0xad, 0xd6, 0x31, 0xe5, 0x52, 0x34, 0x37, 0x4a, 0xca,
      0x76, 0xca, 0x54, 0x7f, 0xec, 0xf7, 0x56, 0x04, 0x50, 0xae, 0x0a, 0x19,
      0x1b, 0xb0, 0x5a, 0x49, 0xcf, 0x23, 0x36, 0x1a, 0x67, 0x3c, 0x2a, 0x86,
      0xc9, 0x68, 0xe0, 0x44, 0x58, 0x61, 0x0c, 0x0c, 0xb7, 0xba, 0x79, 0x8d,
      0x96, 0xa9, 0x4e, 0xff, 0x5f, 0xd0, 0x30, 0xa1, 0x7b, 0x7f, 0x6e, 0x58,
      0xaa, 0x95, 0x83, 0x05, 0x00, 0x05, 0x22, 0x03, 0x9b, 0x00, 0x64, 0x81,
      0xff, 0xfb, 0x54, 0x64, 0x05, 0x01, 0x01, 0x6c, 0x0b, 0x57, 0xf1, 0x2f,
      0x48, 0xa0, 0x17, 0x60, 0x0b, 0x3f, 0x04, 0x23, 0x01, 0x05, 0x50, 0x53,
      0x55, 0x87, 0xb0, 0x65, 0x00, 0x5a, 0x80, 0x6a, 0x20, 0x00, 0x88, 0x00,
      0x81, 0xe0, 0x32, 0xab, 0x4e, 0x84, 0xfc, 0xa4, 0x84, 0x74, 0xe0, 0xd7,
      0x9a, 0xed, 0x3a, 0x1a, 0x9e, 0x25, 0xd2, 0xc5, 0x44, 0xc7, 0x80, 0x41,
      0xdf, 0x3c, 0xa2, 0x0d, 0x6b, 0xbe, 0xf9, 0xe8, 0x89, 0x4c, 0xc1, 0xa9,
      0x60, 0x40, 0x03, 0x60, 0x00, 0x18, 0x31, 0x00, 0x00, 0x80, 0x56, 0x2b,
      0x8b, 0x29, 0x3f, 0xf1, 0x88, 0xbf, 0xfd, 0x5f, 0xe7, 0x55, 0x35, 0x00,
      0xa0, 0x04, 0x48, 0x30, 0x27, 0x7d, 0x55, 0x30, 0x5a, 0x96, 0xd0, 0x15,
      0x0d, 0x27, 0x87, 0xed, 0x11, 0x8e, 0x1e, 0x65, 0xb7, 0x21, 0x34, 0x2a,
      0x2b, 0xcb, 0x98, 0x08, 0x9a, 0x03, 0x13, 0x0a, 0x11, 0x89, 0x64, 0x9c,
      0xd5, 0x94, 0x1e, 0xfb, 0xbd, 0x18, 0x00, 0x50, 0x00, 0x07, 0x97, 0x7b,
      0x48, 0x9f, 0x14, 0x20, 0x1a, 0xf1, 0x80, 0x74, 0xf6, 0x65, 0x1b, 0x15,
      0x30, 0x9a, 0xff, 0x97, 0x66, 0x08, 0x04, 0x03, 0x43, 0x32, 0x55, 0x20,
      0x58, 0xa3, 0x45, 0x07, 0x4e, 0x2d, 0x30, 0x84, 0x42, 0x26, 0x64, 0x35,
      0x0d, 0x67, 0x5c, 0x83, 0x62, 0x15, 0xa4, 0x33, 0x2d, 0x69, 0xa7, 0x77,
      0xff, 0xfb, 0x54, 0x64, 0x10, 0x00, 0x01, 0x68, 0x09, 0x57, 0x70, 0xcc,
      0x48, 0xa8, 0x15, 0xc0, 0x5b, 0x6c, 0x04, 0xc6, 0x01, 0x85, 0x94, 0x31,
      0x5b, 0xe4, 0xb0, 0xc0, 0xa0, 0x5c, 0x80, 0x29, 0xa0, 0x10, 0x88, 0xe0,
      0x56, 0x91, 0x23, 0x3f, 0x59, 0xc5, 0x3f, 0x77, 0xff, 0xe8, 0x45, 0x4f,
      0x99, 0xdf, 0x60, 0x00, 0x90, 0x46, 0x30, 0x00, 0x06, 0x0c, 0x24, 0x40,
      0x3b, 0xf2, 0xbb, 0x75, 0x53, 0xfb, 0x91, 0xff, 0xef, 0x57, 0xa5, 0xd8,
      0xa0, 0xc4, 0x11, 0x54, 0xc4, 0x69, 0x20, 0x00, 0x70, 0x84, 0xb2, 0x98,
      0xe0, 0x62, 0x25, 0xa1, 0x40, 0x85, 0x14, 0x3f, 0xe1, 0xd6, 0x77, 0xb1,
      0x9a, 0xe5, 0x64, 0x90, 0x3c, 0xe8, 0x7d, 0x2c, 0x14, 0xd9, 0x85, 0x43,
      0x68, 0xfd, 0x85, 0x0d, 0x22, 0x59, 0xa2, 0xf0, 0x40, 0x04, 0xa0, 0x09,
      0x8c, 0x34, 0x39, 0x69, 0xeb, 0x00, 0x63, 0x58, 0x58, 0x7a, 0x1c, 0xb4,
      0x6a, 0x65, 0x5f, 0x7d, 0x2e, 0x66, 0x95, 0x78, 0x58, 0x54, 0x67, 0x76,
      0x69, 0xb5, 0x80, 0x00, 0x07, 0x43, 0xf1, 0xb2, 0x10, 0x4e, 0xa4, 0xb4,
      0x1c, 0x21, 0x11, 0x7a, 0x0a, 0xa1, 0x41, 0x02, 0xf6, 0xdd, 0x5e, 0x52,
      0x79, 0xc3, 0x9b, 0x72, 0x4b, 0x56, 0x1a, 0x7c, 0xb1, 0xd8, 0x4a, 0x04,
      0x6b, 0xab, 0x5e, 0x9c, 0x06, 0x10, 0x0b, 0x63, 0x91, 0x80, 0x00, 0x01,
      0xff, 0xfb, 0x54, 0x64, 0x1a, 0x80, 0x01, 0x64, 0x19, 0x5e, 0xfd, 0x30,
      0x60, 0x0c, 0x18, 0x20, 0x0b, 0x6d, 0xa0, 0x88, 0x01, 0x8b, 0x54, 0xef,
      0x71, 0xb8, 0xc4, 0x00, 0x10, 0x9c, 0x89, 0x2e, 0xb7, 0x04, 0x20, 0x02,
      0x2c, 0x07, 0x0f, 0x71, 0x12, 0xdc, 0xf4, 0x33, 0x38, 0xd6, 0x9e, 0x4d,
      0x41, 0x94, 0xb7, 0x52, 0x25, 0x21, 0x59, 0x49, 0xc4, 0xa1, 0x10, 0x86,
      0x88, 0x40, 0x20, 0x1a, 0x00, 0x7a, 0xc6, 0x1c, 0xd4, 0xd0, 0x39, 0x72,
      0xda, 0x35, 0xcf, 0x60, 0x50, 0x09, 0xc4, 0xba, 0xb0, 0x84, 0x47, 0x05,
      0xc1, 0xf3, 0x18, 0xe8, 0xa1, 0xf8, 0x60, 0x5a, 0x0f, 0x28, 0xc1, 0x42,
      0x04, 0xb0, 0xbb, 0xa8, 0xf5, 0x13, 0x04, 0x79, 0x80, 0xdc, 0x2b, 0x46,
      0xa0, 0xc1, 0x33, 0xf7, 0xf8, 0x47, 0x1e, 0x60, 0xa7, 0x52, 0xb2, 0x57,
      0xff, 0xea, 0xd0, 0xb6, 0x7c, 0x54, 0xff, 0xff, 0xff, 0xf5, 0x32, 0xe4,
      0x87, 0xf7, 0x7f, 0xf8, 0xf4, 0xf9, 0x71, 0x12, 0x75, 0x06, 0x28, 0x15,
      0x8a, 0x05, 0x02, 0xa5, 0x40, 0x80, 0x40, 0x18, 0x10, 0x18, 0x00, 0x01,
      0x7f, 0x16, 0x9d, 0x3e, 0x73, 0xfb, 0x21, 0xd6, 0xd6, 0xbc, 0x27, 0x82,
      0x07, 0x2f, 0xaf, 0x26, 0xef, 0xec, 0x7f, 0xfd, 0x65, 0xf6, 0xf1, 0x60,
      0x0d, 0xca, 0x90, 0x80, 0x6c, 0x6e, 0x40, 0x18, 0x05, 0xa0, 0x22, 0x07,
      0xff, 0xfb, 0x54, 0x64, 0x05, 0x00, 0x11, 0x5a, 0x1b, 0x5b, 0x67, 0x3c,
      0x40, 0x00, 0x14, 0x40, 0x0c, 0x0b, 0xe0, 0x88, 0x01, 0x85, 0x9c, 0x25,
      0x83, 0x86, 0x20, 0x68, 0x70, 0x51, 0x81, 0xae, 0xf4, 0x90, 0x18, 0x02,
      0x81, 0x97, 0x1c, 0xef, 0x20, 0xe8, 0xfa, 0xcf, 0x46, 0x4a, 0x43, 0xbd,
      0x32, 0x45, 0x59, 0xd1, 0xac, 0x7e, 0xdf, 0xdb, 0x63, 0xba, 0xa1, 0x28,
      0x44, 0x30, 0x24, 0x17, 0x10, 0x7f, 0xd9, 0x0a, 0x7a, 0x38, 0x00, 0x0d,
      0x80, 0xc4, 0x40, 0x1b, 0xe1, 0x82, 0x8d, 0xe9, 0x30, 0xaf, 0xfc, 0x6f,
      0xff, 0xff, 0xec, 0xfc, 0xe9, 0x5c, 0x61, 0x72, 0x5b, 0x26, 0x8a, 0xc0,
      0x2e, 0x22, 0x69, 0x69, 0x59, 0x24, 0x6b, 0x11, 0x8d, 0x9a, 0x07, 0x56,
      0x8b, 0xed, 0x12, 0xa3, 0xad, 0x3a, 0x55, 0x75, 0x85, 0x31, 0x61, 0xc1,
      0x88, 0xf5, 0x20, 0x0a, 0x18, 0x1e, 0x8e, 0xa7, 0x83, 0x33, 0x57, 0xff,
      0x41, 0xa2, 0x3c, 0x40, 0x0c, 0x80, 0x08, 0x02, 0x24, 0xe3, 0xa1, 0xaf,
      0x7b, 0x14, 0xcf, 0xdc, 0xff, 0xfa, 0x52, 0x13, 0x38, 0xef, 0xa6, 0xc6,
      0x11, 0xab, 0xad, 0xb0, 0x0b, 0x94, 0x00, 0xb4, 0x55, 0x09, 0x12, 0x52,
      0xa7, 0x3f, 0x60, 0x47, 0x8b, 0x48, 0xb3, 0x3b, 0x2b, 0x94, 0x5e, 0x15,
      0x50, 0x24, 0xba, 0x5e, 0x7f, 0x02, 0xad, 0xdb, 0xd5, 0x34, 0xda, 0x32,
      0xff, 0xfb, 0x54, 0x64, 0x12, 0x80, 0x31, 0x71, 0x0a, 0xdf, 0x69, 0x8f,
      0x31, 0x24, 0x17, 0x60, 0x3b, 0xbf, 0x18, 0x22, 0x01, 0x05, 0xac, 0x5b,
      0x71, 0xe4, 0xb0, 0x41, 0x80, 0x50, 0x80, 0xed, 0x50, 0x50, 0x08, 0x00,
      0xc2, 0xc4, 0x45, 0xef, 0xfe, 0x2a, 0x98, 0x47, 0x8a, 0x72, 0x00, 0x10,
      0x30, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x01, 0xc0, 0x80, 0xc4, 0x5b, 0x77,
      0xff, 0xff, 0xfd, 0xda, 0x94, 0xf5, 0xc8, 0x7e, 0xaa, 0x01, 0x00, 0x48,
      0x63, 0x25, 0x68, 0x04, 0x38, 0x01, 0x41, 0xf6, 0x03, 0x19, 0x2e, 0x07,
      0xb4, 0xb8, 0x8e, 0xa3, 0xcc, 0x5c, 0xb8, 0xaf, 0xb4, 0x16, 0x9a, 0x6a,
      0x6f, 0x9b, 0x2e, 0x0d, 0xa1, 0x05, 0x2e, 0x0f, 0x4f, 0x21, 0x47, 0x3a,
      0xe8, 0xff, 0xea, 0x09, 0xa7, 0xdb, 0xc1, 0x00, 0x71, 0x40, 0x85, 0x1a,
      0x4a, 0x0f, 0x16, 0x1f, 0xbf, 0xfe, 0xb6, 0x1d, 0x12, 0xb9, 0x0d, 0x71,
      0x57, 0x18, 0xa0, 0x80, 0xac, 0x60, 0x80, 0x18, 0x05, 0x9b, 0xcc, 0xc4,
      0xae, 0x94, 0xc2, 0x5e, 0x3a, 0x90, 0x7d, 0x1b, 0xa3, 0xb5, 0xc0, 0x04,
      0x8b, 0xb5, 0x34, 0xd7, 0xf6, 0xcd, 0x8c, 0xc2, 0x4e, 0x8c, 0xf1, 0xa6,
      0xaa, 0xb4, 0x71, 0x33, 0xa8, 0xd5, 0x62, 0xeb, 0x5c, 0x00, 0x00, 0x00,
      0x02, 0xa8, 0x02, 0x3c, 0x01, 0x58, 0xbb, 0xfd, 0x85, 0x3f, 0xfd, 0xb7,
      0xff, 0xfb, 0x54, 0x64, 0x1d, 0x00, 0x11, 0x55, 0x1c, 0xda, 0xe1, 0xe6,
      0x2a, 0x10, 0x15, 0xc0, 0x2b, 0xfe, 0x2c, 0x02, 0x01, 0x85, 0x94, 0x2f,
      0x87, 0x87, 0x99, 0x28, 0x70, 0x51, 0x04, 0xae, 0x78, 0x60, 0xa4, 0x64,
      0x7f, 0xeb, 0x44, 0xc7, 0x6e, 0x9d, 0x1d, 0xd6, 0xb6, 0xda, 0xce, 0x6b,
      0xc0, 0x84, 0x91, 0x49, 0x21, 0x70, 0x8b, 0x33, 0xaa, 0x96, 0x54, 0x8c,
      0x50, 0xda, 0xc0, 0xb3, 0xb4, 0x66, 0x7e, 0x98, 0x2d, 0x45, 0xa9, 0xb5,
      0x73, 0xaa, 0xaa, 0xc2, 0xf0, 0xe3, 0xba, 0x08, 0xb9, 0x9b, 0x3f, 0x7b,
      0x0e, 0x69, 0x98, 0xd6, 0x00, 0x58, 0x0d, 0xa9, 0x02, 0x00, 0x39, 0x2b,
      0x6d, 0x63, 0x45, 0xc0, 0x62, 0x39, 0x86, 0x0b, 0x2b, 0xfd, 0x83, 0x2a,
      0xc4, 0x3c, 0x02, 0x00, 0xd4, 0xb6, 0x5e, 0x4d, 0xf9, 0xe8, 0xc8, 0xf2,
      0x6e, 0xd5, 0x65, 0xc2, 0x4e, 0x12, 0x45, 0x51, 0xcd, 0x4c, 0xb4, 0x37,
      0xd1, 0xe5, 0x6d, 0x2a, 0xc7, 0x1a, 0x0b, 0x0d, 0x56, 0xc6, 0x90, 0xd3,
      0xa7, 0x2f, 0x0b, 0xc3, 0x54, 0xeb, 0x2e, 0xa7, 0x35, 0x70, 0x01, 0x01,
      0x78, 0x18, 0x02, 0x00, 0x43, 0xfe, 0x44, 0xa8, 0x2d, 0x3e, 0xbb, 0x3f,
      0xff, 0xff, 0xa6, 0x04, 0x14, 0xa9, 0xa6, 0xc9, 0x08, 0x0a, 0x04, 0xab,
      0xa4, 0xc9, 0xec, 0xf5, 0xa8, 0xf2, 0xb6, 0xc9, 0x0c, 0x80, 0xa0, 0x08,
      0xff, 0xfb, 0x54, 0x64, 0x2a, 0x00, 0x81, 0x6a, 0x1e, 0xd8, 0xc3, 0x05,
      0x32, 0x72, 0x11, 0x81, 0x4b, 0xcc, 0x04, 0x03, 0x43, 0x85, 0xac, 0x35,
      0x6d, 0xa7, 0x98, 0x68, 0x50, 0x4c, 0x03, 0x6e, 0x70, 0x60, 0x08, 0x26,
      0xe8, 0x27, 0xa5, 0x0e, 0x16, 0x16, 0x13, 0x0e, 0x83, 0x7d, 0x40, 0xcb,
      0xd8, 0xed, 0x71, 0xee, 0xb5, 0xed, 0xd9, 0xff, 0xff, 0xfe, 0x19, 0x0d,
      0xfa, 0x00, 0x20, 0x02, 0x0a, 0x16, 0x18, 0x2c, 0x65, 0xdf, 0xfc, 0x93,
      0xff, 0xff, 0xff, 0xff, 0xff, 0x94, 0x02, 0xd5, 0x81, 0x94, 0xb5, 0x92,
      0x60, 0x22, 0x03, 0x85, 0xea, 0x4d, 0x41, 0x97, 0x84, 0x71, 0x91, 0x51,
      0xae, 0x53, 0xa8, 0xcb, 0x2d, 0xe5, 0x64, 0x59, 0x80, 0x63, 0x0b, 0x82,
      0x6d, 0xd2, 0x40, 0x2b, 0x59, 0xa5, 0x0b, 0x3d, 0x15, 0x95, 0x97, 0x30,
      0xf4, 0xff, 0xe8, 0x1a, 0x81, 0x60, 0x01, 0x01, 0x08, 0xfc, 0x00, 0xc0,
      0x00, 0x4d, 0x31, 0x00, 0x7d, 0x3b, 0x43, 0x55, 0xde, 0xb3, 0x4f, 0xf6,
      0xb7, 0xff, 0x2b, 0x01, 0x29, 0x69, 0xab, 0xd0, 0x58, 0x0c, 0xc7, 0x45,
      0x0c, 0xdc, 0x29, 0x0d, 0xfd, 0xb5, 0x47, 0xc6, 0xef, 0x69, 0x2d, 0x5a,
      0x14, 0x9c, 0xdd, 0x19, 0x59, 0xcf, 0x93, 0xe6, 0x78, 0xa1, 0x98, 0xee,
      0x8e, 0x73, 0x22, 0x42, 0x22, 0x09, 0xee, 0x4c, 0x81, 0x5f, 0xec, 0xc4,
      0xff, 0xfb, 0x54, 0x64, 0x38, 0x00, 0x11, 0x5f, 0x0b, 0xdb, 0xe1, 0x2f,
      0x48, 0x0c, 0x17, 0x00, 0x6b, 0x3f, 0x04, 0x22, 0x00, 0x05, 0xb0, 0x7b,
      0x5d, 0x94, 0xf1, 0x00, 0x00, 0x54, 0x85, 0xef, 0xfa, 0x8a, 0x30, 0x06,
      0x0c, 0xac, 0x0c, 0x13, 0x33, 0x00, 0x06, 0x52, 0x57, 0x7d, 0x1b, 0x22,
      0x01, 0xc4, 0x95, 0x42, 0x36, 0xc1, 0x8c, 0x7f, 0xfe, 0xa5, 0x00, 0x00,
      0x34, 0xbb, 0x5d, 0xb2, 0x08, 0x01, 0x40, 0x3b, 0x85, 0xeb, 0x20, 0x9e,
      0xbb, 0x20, 0x21, 0x74, 0xac, 0x39, 0x95, 0x2d, 0x99, 0x68, 0x6c, 0x62,
      0x55, 0x27, 0x4c, 0xd7, 0x38, 0x89, 0x40, 0x60, 0x9d, 0xe5, 0x50, 0x8d,
      0x41, 0xe2, 0xc6, 0xcd, 0xbe, 0xd7, 0xba, 0xea, 0x75, 0xd4, 0x0e, 0x09,
      0x51, 0x10, 0xe3, 0xac, 0x99, 0x33, 0x58, 0x2b, 0x24, 0x32, 0x6d, 0x2f,
      0x05, 0xf0, 0x72, 0xf5, 0x88, 0x15, 0x62, 0x76, 0xb4, 0xd9, 0x9e, 0x78,
      0x6c, 0x2f, 0xce, 0x77, 0x51, 0x8c, 0x25, 0xd7, 0x88, 0x60, 0x87, 0x72,
      0xc6, 0x78, 0x6b, 0x9c, 0xe7, 0x0b, 0x00, 0x00, 0x30, 0x12, 0x6d, 0xb5,
      0x4c, 0x00, 0x00, 0x58, 0x00, 0x11, 0xfd, 0x61, 0x8b, 0xa8, 0x4f, 0xe1,
      0x3a, 0xf6, 0x48, 0x91, 0xac, 0x69, 0x83, 0x43, 0x7b, 0x3a, 0xf3, 0x2b,
      0x58, 0xb7, 0x34, 0xb2, 0x25, 0xb1, 0x72, 0x9c, 0x34, 0x16, 0xb4, 0x5c,
      0xff, 0xfb, 0x54, 0x64, 0x43, 0x00, 0x02, 0xe0, 0x2f, 0x54, 0xde, 0x3d,
      0x20, 0x02, 0x42, 0xc4, 0xba, 0x9c, 0xc2, 0x98, 0x00, 0x45, 0x58, 0x1f,
      0x49, 0x9c, 0x61, 0x00, 0x00, 0x67, 0x00, 0x28, 0xb7, 0x80, 0x20, 0x00,
      0x94, 0x79, 0xbf, 0x96, 0x74, 0xcf, 0xeb, 0x66, 0x4f, 0xcf, 0x4b, 0x14,
      0x9f, 0x8d, 0x02, 0x8d, 0x56, 0x5f, 0xdf, 0xe8, 0x46, 0x5b, 0xd9, 0x1d,
      0xf2, 0x58, 0x94, 0x86, 0x48, 0x00, 0xb0, 0x07, 0x12, 0x01, 0x24, 0xe0,
      0xa0, 0xa0, 0x10, 0x09, 0x20, 0x11, 0x22, 0x44, 0x89, 0x03, 0x40, 0xcb,
      0x96, 0x0a, 0x82, 0xa7, 0xbf, 0x12, 0x82, 0xa0, 0xd0, 0x76, 0x58, 0x39,
      0xfc, 0x1a, 0x3d, 0xfc, 0x15, 0x3b, 0xc1, 0xa0, 0x00, 0x02, 0x5e, 0x04,
      0x00, 0x00, 0x00, 0x1f, 0x82, 0xa0, 0xa8, 0x2a, 0x79, 0xbe, 0x54, 0x15,
      0x05, 0x7f, 0x05, 0x41, 0x50, 0x54, 0x1a, 0xe7, 0x65, 0x95, 0x4c, 0x41,
      0x4d, 0x45, 0x33, 0x2e, 0x31, 0x30, 0x30, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55
    };
}

#endif /* ATE_OK_SOUND_H_ */

#pragma once
typedef __m128i xmm_t;
#define	XMM_SIZE	(sizeof(xmm_t))
#define	XMM_MASK	(XMM_SIZE - 1)
typedef union rte_xmm {
    xmm_t    x;
    uint8_t  u8[XMM_SIZE / sizeof(uint8_t)];
    uint16_t u16[XMM_SIZE / sizeof(uint16_t)];
    uint32_t u32[XMM_SIZE / sizeof(uint32_t)];
    uint64_t u64[XMM_SIZE / sizeof(uint64_t)];
    double   pd[XMM_SIZE / sizeof(double)];
} rte_xmm_t;

uint64_t _mm_cvtsi128_si64(__m128i a) {
    rte_xmm_t m;
    m.x = (a);
    return (m.u64[0]);
}
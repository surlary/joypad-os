/* mbedtls_config.h — TLS client minimal */
#ifndef MBEDTLS_CONFIG_H
#define MBEDTLS_CONFIG_H

/* 平台与熵 */
#define MBEDTLS_PLATFORM_C
#define MBEDTLS_NO_PLATFORM_ENTROPY    /* 必须禁用平台熵 */
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_CTR_DRBG_C
/* 你需要在工程中实现：
   int mbedtls_hardware_poll(void *data, unsigned char *out, size_t len, size_t *olen);
   用可靠熵源（如 Pico W 无线芯片 RNG）填充随机数。 */

/* 椭圆曲线 & 算法（ECDHE/ECDSA） */
#define MBEDTLS_BIGNUM_C
#define MBEDTLS_ECP_C
#define MBEDTLS_ECDH_C
#define MBEDTLS_ECDSA_C
/* 至少启用一种短魏尔斯曲线；仅启用 CURVE25519 并不能满足 ECDSA/ECP 的前置条件 */
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
/* 如需 X25519，可额外启用：
   #define MBEDTLS_ECP_DP_CURVE25519_ENABLED */

/* 加解密与散列（选用 GCM 套件） */
#define MBEDTLS_AES_C
#define MBEDTLS_GCM_C
#define MBEDTLS_SHA256_C
#define MBEDTLS_MD_C
#define MBEDTLS_CIPHER_C

/* X.509/PEM 证书解析 */
#define MBEDTLS_OID_C
#define MBEDTLS_ASN1PARSE_C
#define MBEDTLS_X509_USE_C
#define MBEDTLS_X509_CRT_PARSE_C
#define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_BASE64_C
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C

/* TLS 协议（仅客户端） */
#define MBEDTLS_SSL_TLS_C
#define MBEDTLS_SSL_CLI_C
#define MBEDTLS_SSL_PROTO_TLS1_2

/* 若构建于 Mbed TLS 2.x，需要至少启用一种密钥交换： */
#define MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED
/* 若是 Mbed TLS 3.x，请删除上面这一行（3.x 无 KEY_EXCHANGE 宏）。 */

/* 内存占用优化（可按需调整） */
#define MBEDTLS_SSL_MAX_CONTENT_LEN 4096

// #include "mbedtls/check_config.h"
#endif

/********************************** (C) COPYRIGHT *******************************
 * File Name          : app.h
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2021/11/18
 * Description        :
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#ifndef app_H
#define app_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

#define APP_NODE_EVT                   (1 << 0)
#define APP_NODE_PROVISION_EVT         (1 << 1)
#define APP_DELETE_NODE_TIMEOUT_EVT    (1 << 2)
#define APP_DELETE_LOCAL_NODE_EVT      (1 << 3)
#define APP_DELETE_NODE_INFO_EVT       (1 << 4)

#define CMD_PROVISION_INFO                 0xA0
#define CMD_PROVISION_INFO_ACK             0x80
#define CMD_PROVISION                      0xA1
#define CMD_PROVISION_ACK                  0x81
#define CMD_DELETE_NODE                0xA2
#define CMD_DELETE_NODE_ACK            0x82
#define CMD_DELETE_NODE_INFO           0xA3
#define CMD_LOCAL_RESET                0xAF

#define PERIPHERAL_CMD_LEN             1
#define PROVISION_NET_KEY_LEN          16
#define ADDRESS_LEN                    2

// ÉèÖÃÅäÍøÐÅÏ¢ÃüÁî£¬°üº¬ 1×Ö½ÚÃüÁîÂë+1×Ö½Ú¿ØÖÆ×Ö+4×Ö½Úiv index+1×Ö½Ú¸üÐÂ±êÖ¾flag
#define PROVISION_INFO_DATA_LEN            (PERIPHERAL_CMD_LEN + 1 + 4 + 1)
// ÉèÖÃÅäÍøÐÅÏ¢ÃüÁîÓ¦´ð£¬°üº¬ 1×Ö½ÚÃüÁîÂë+1×Ö½Ú×´Ì¬Âë+4×Ö½Úiv index+1×Ö½Ú¸üÐÂ±êÖ¾flag
#define PROVISION_INFO_ACK_DATA_LEN        (PERIPHERAL_CMD_LEN + 1 + 4 + 1)
// ÉèÖÃÅäÍøÃüÁî£¬°üº¬ 1×Ö½ÚÃüÁîÂë+16×Ö½ÚÍøÂçÃÜÔ¿+2×Ö½ÚÍøÂçµØÖ·
#define PROVISION_DATA_LEN                 (PERIPHERAL_CMD_LEN + PROVISION_NET_KEY_LEN + ADDRESS_LEN)
// ÉèÖÃÅäÍøÃüÁîÓ¦´ð£¬°üº¬ 1×Ö½ÚÃüÁîÂë+2×Ö½ÚÍøÂçµØÖ·+1×Ö½Ú×´Ì¬Âë
#define PROVISION_ACK_DATA_LEN             (PERIPHERAL_CMD_LEN + ADDRESS_LEN + 1)
// É¾³ý½ÚµãÃüÁî£¬°üº¬ 1×Ö½ÚÃüÁîÂë+2×Ö½ÚÐèÒªÉ¾³ýµÄ½ÚµãµØÖ·
#define DELETE_NODE_DATA_LEN           (PERIPHERAL_CMD_LEN + ADDRESS_LEN)
// É¾³ý½ÚµãÃüÁîÓ¦´ð£¬°üº¬ 1×Ö½ÚÃüÁîÂë
#define DELETE_NODE_ACK_DATA_LEN       (PERIPHERAL_CMD_LEN)
// É¾³ý´æ´¢µÄ½ÚµãÐÅÏ¢ÃüÁî£¬°üº¬ 1×Ö½ÚÃüÁîÂë
#define DELETE_NODE_INFO_DATA_LEN      (PERIPHERAL_CMD_LEN)
// ±¾µØ¸´Î»ÃüÁî£¬°üº¬ 1×Ö½ÚÃüÁîÂë
#define LOCAL_RESET_DATA_LEN           (PERIPHERAL_CMD_LEN)
// ×´Ì¬Âë¶¨Òå
#define STATUS_SUCCESS                     0x00
#define STATUS_TIMEOUT                     0x01
#define STATUS_NOMEM                       0x02
#define STATUS_INVALID                     0x03

/******************************************************************************/

typedef struct
{
    uint16_t node_addr;
    uint16_t elem_count;
    uint16_t net_idx;
    uint16_t retry_cnt : 12,
        fixed : 1,
        blocked : 1;

} node_t;

typedef union
{
    struct
    {
        uint8_t cmd;         /* ÃüÁîÂë CMD_PROVISION_INFO */
        uint8_t set_flag;    /* ¿ØÖÆ×Ö Îª1±íÊ¾ÉèÖÃ£¬Îª0±íÊ¾²éÑ¯*/
        uint8_t iv_index[4]; /* iv index */
        uint8_t flag;        /* Net key refresh flag */
    } provision_info;        /* ÅäÍøÐÅÏ¢ÃüÁî */
    struct
    {
        uint8_t cmd;         /* ÃüÁîÂë CMD_PROVISION_INFO_ACK */
        uint8_t status;      /* ×´Ì¬Âë*/
        uint8_t iv_index[4]; /* iv index */
        uint8_t flag;        /* Net key refresh flag */
    } provision_info_ack;    /* ÅäÍøÐÅÏ¢ÃüÁîÓ¦´ð */
    struct
    {
        uint8_t cmd;                            /* ÃüÁîÂë CMD_PROVISION */
        uint8_t net_key[PROVISION_NET_KEY_LEN]; /* ºóÐøÊý¾Ý³¤¶È */
        uint8_t addr[ADDRESS_LEN];              /* ÅäÍøµØÖ· */
    } provision;                                /* ÅäÍøÃüÁî */
    struct
    {
        uint8_t cmd;               /* ÃüÁîÂë CMD_PROVISION_ACK */
        uint8_t addr[ADDRESS_LEN]; /* ÅäÍøµØÖ· */
        uint8_t status;            /* ×´Ì¬Âë±¸ÓÃ */
    } provision_ack;               /* ÅäÍøÃüÁîÓ¦´ð */
    struct
    {
        uint8_t cmd;                /* ÃüÁîÂë CMD_DELETE_NODE */
        uint8_t addr[ADDRESS_LEN]; /* É¾³ýµØÖ· */
    } delete_node;                  /* É¾³ý½ÚµãÃüÁî */
    struct
    {
        uint8_t cmd;                /* ÃüÁîÂë CMD_DELETE_NODE_ACK */
    } delete_node_ack;              /* É¾³ý½ÚµãÃüÁîÓ¦´ð */
    struct
    {
        uint8_t cmd;                /* ÃüÁîÂë CMD_DELETE_NODE_INFO */
    } delete_node_info;             /* É¾³ý´æ´¢µÄ½ÚµãÐÅÏ¢ÃüÁî */
    struct
    {
        uint8_t cmd;                /* ÃüÁîÂë CMD_LOCAL_RESET */
    } local_reset;                  /* ±¾µØ»Ö¸´³ö³§ÉèÖÃÃüÁî */
    struct
    {
        uint8_t buf[20]; /* ½ÓÊÕÊý¾Ý°ü*/
    } data;
}app_mesh_manage_t;

void App_Init(void);

void App_peripheral_reveived(uint8_t *pValue, uint16_t len);

/******************************************************************************/

/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif

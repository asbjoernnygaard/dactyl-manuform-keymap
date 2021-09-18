#include QMK_KEYBOARD_H
#include "keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum combo_events {
    /* Backspace steno-lite combos */
    // These let me type common words and n-grams
    // more quickly, in one single stroke.
    BSPCEV_EVERY,
    BSPCU_YOU,
    BSPCA_AND,
    BSPCN_NOT,
    BSPCW_WITH,
    BSPCF_FOR,
    BSPCH_HERE,
    BSPCT_THE,
    BSPCM_MENT,
    BSPCG_ING,
    BSPCO_OUGH,
    BSPCI_ION,
    BSPCIS_IONS,
    BSPCTA_THAT,
    BSPCQ_QUE,
    // I use the word "key" much more frequently than the common folk
    // and if you're reading this, you probably do too
    BSPCK_KEY,
    BSPCTS_THIS,
    BSPCDN_DONT,
    BSPCIT_IN_THE,

    /* Other steno-lite combos */
    // Additional steno-lite combos for common words and n-grams
    // that do not involve the backspace thumb key because these
    // combinations of keys do not generate too many conflicts
    // in normal typing.
    JU_JUST,
    HV_HAVE,
    QK_QMK,
    KB_KEYBOARD,
    WA_WHAT,

    /* Non-alphanumeric combos */
    // Combos for which the output isn't one or more alphanumeric characters
    UYCLN_INDEX,
    OS_SFT_CAPS,
    REPX_BSLS,
    BSPCE_ESC,
    DOTSLASH_UPDIR,
    ZEROEIGHT_COMMA,
    EIGHTNINE_DOT,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_E_V_COMBO[]   = {KC_BSPC,  HOME_E,  KC_V,    COMBO_END};
const uint16_t PROGMEM BSPC_U_COMBO[]     = {KC_BSPC,  KC_U,    COMBO_END};
const uint16_t PROGMEM BSPC_A_COMBO[]     = {KC_BSPC,  HOME_A,  COMBO_END};
const uint16_t PROGMEM BSPC_N_COMBO[]     = {KC_BSPC,  HOME_N,  COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[]     = {KC_BSPC,  KC_W,    COMBO_END};
const uint16_t PROGMEM BSPC_F_COMBO[]     = {KC_BSPC,  KC_F,    COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[]     = {KC_BSPC,  KC_H,    COMBO_END};
const uint16_t PROGMEM BSPC_T_COMBO[]     = {KC_BSPC,  HOME_T,  COMBO_END};
const uint16_t PROGMEM BSPC_M_COMBO[]     = {KC_BSPC,  KC_M,    COMBO_END};
const uint16_t PROGMEM BSPC_G_COMBO[]     = {KC_BSPC,  KC_G,    COMBO_END};
const uint16_t PROGMEM BSPC_O_COMBO[]     = {KC_BSPC,  HOME_O,  COMBO_END};
const uint16_t PROGMEM BSPC_I_COMBO[]     = {KC_BSPC,  HOME_I,  COMBO_END};
const uint16_t PROGMEM BSPC_I_S_COMBO[]   = {KC_BSPC,  HOME_I,  HOME_S,  COMBO_END};
const uint16_t PROGMEM BSPC_Q_COMBO[]     = {KC_BSPC,  KC_Q,    COMBO_END};
const uint16_t PROGMEM BSPC_K_COMBO[]     = {KC_BSPC,  KC_K,    COMBO_END};
const uint16_t PROGMEM BSPC_T_S_COMBO[]   = {KC_BSPC,  HOME_T,  HOME_S,  COMBO_END};
const uint16_t PROGMEM K_B_COMBO[]        = {KC_K,     KC_B,    COMBO_END};
const uint16_t PROGMEM BSPC_T_A_COMBO[]   = {KC_BSPC,  HOME_T,  HOME_A,  COMBO_END};
const uint16_t PROGMEM BSPC_D_N_COMBO[]   = {KC_BSPC,  KC_D,    HOME_N,  COMBO_END};
const uint16_t PROGMEM BSPC_I_T_COMBO[]   = {KC_BSPC,  HOME_I,  HOME_T,  COMBO_END};
const uint16_t PROGMEM J_U_COMBO[]        = {KC_J,     KC_U,    COMBO_END};
const uint16_t PROGMEM H_V_COMBO[]        = {KC_H,     KC_V,    COMBO_END};
const uint16_t PROGMEM Q_K_COMBO[]        = {KC_Q,     KC_K,    COMBO_END};
const uint16_t PROGMEM W_A_COMBO[]        = {KC_W,     HOME_A,  COMBO_END};
const uint16_t PROGMEM U_Y_SCLN_COMBO[]   = {KC_U,     KC_Y,    KC_SCLN, COMBO_END};
const uint16_t PROGMEM OS_SFT_COMBO[]     = {OS_LSFT,  OS_RSFT, COMBO_END};
const uint16_t PROGMEM REP_X_COMBO[]      = {REPEAT,   KC_X,    COMBO_END};
const uint16_t PROGMEM BSPC_E_COMBO[]     = {KC_BSPC,  HOME_E,  COMBO_END};
const uint16_t PROGMEM DOT_SLASH_COMBO[]  = {TD_DOT,   KC_SLSH, COMBO_END};
const uint16_t PROGMEM ZERO_EIGHT_COMBO[] = {KC_0,     KC_8,    COMBO_END};
const uint16_t PROGMEM EIGHT_NINE_COMBO[] = {KC_8,     KC_9,    COMBO_END};

combo_t key_combos[] = {
    [BSPCEV_EVERY]    = COMBO_ACTION(BSPC_E_V_COMBO),
    [BSPCU_YOU]       = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCA_AND]       = COMBO_ACTION(BSPC_A_COMBO),
    [BSPCN_NOT]       = COMBO_ACTION(BSPC_N_COMBO),
    [BSPCW_WITH]      = COMBO_ACTION(BSPC_W_COMBO),
    [BSPCF_FOR]       = COMBO_ACTION(BSPC_F_COMBO),
    [BSPCH_HERE]      = COMBO_ACTION(BSPC_H_COMBO),
    [BSPCT_THE]       = COMBO_ACTION(BSPC_T_COMBO),
    [BSPCM_MENT]      = COMBO_ACTION(BSPC_M_COMBO),
    [BSPCG_ING]       = COMBO_ACTION(BSPC_G_COMBO),
    [BSPCO_OUGH]      = COMBO_ACTION(BSPC_O_COMBO),
    [BSPCI_ION]       = COMBO_ACTION(BSPC_I_COMBO),
    [BSPCIS_IONS]     = COMBO_ACTION(BSPC_I_S_COMBO),
    [BSPCTA_THAT]     = COMBO_ACTION(BSPC_T_A_COMBO),
    [BSPCQ_QUE]       = COMBO_ACTION(BSPC_Q_COMBO),
    [BSPCK_KEY]       = COMBO_ACTION(BSPC_K_COMBO),
    [BSPCTS_THIS]     = COMBO_ACTION(BSPC_T_S_COMBO),
    [BSPCDN_DONT]     = COMBO_ACTION(BSPC_D_N_COMBO),
    [BSPCIT_IN_THE]   = COMBO_ACTION(BSPC_I_T_COMBO),
    [JU_JUST]         = COMBO_ACTION(J_U_COMBO),
    [HV_HAVE]         = COMBO_ACTION(H_V_COMBO),
    [QK_QMK]          = COMBO_ACTION(Q_K_COMBO),
    [KB_KEYBOARD]     = COMBO_ACTION(K_B_COMBO),
    [WA_WHAT]         = COMBO_ACTION(W_A_COMBO),
    [OS_SFT_CAPS]     = COMBO(OS_SFT_COMBO, CAPS_WORD),
    [REPX_BSLS]       = COMBO(REP_X_COMBO, KC_BSLASH),
    [BSPCE_ESC]       = COMBO(BSPC_E_COMBO, KC_ESC),
    [DOTSLASH_UPDIR]  = COMBO_ACTION(DOT_SLASH_COMBO),
    [ZEROEIGHT_COMMA] = COMBO(ZERO_EIGHT_COMBO, KC_COMMA),
    [EIGHTNINE_DOT]   = COMBO(EIGHT_NINE_COMBO, KC_DOT),
    [UYCLN_INDEX]     = COMBO_ACTION(U_Y_SCLN_COMBO),
};

// 5074 bytes free without using steno_combo
void steno_combo(const char *lowercase, const char *uppercase, const char *ctrlcase, bool pressed, uint8_t mod_state) {
    if (pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            unregister_mods(MOD_MASK_SHIFT);
            send_string(uppercase);
            set_mods(mod_state);
        } else if (ctrlcase && mod_state & MOD_MASK_CTRL) {
            unregister_mods(MOD_MASK_CTRL);
            send_string(ctrlcase);
            set_mods(mod_state);
        } else {
            send_string(lowercase);
        }
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos,
    // like UYCLN_INDEX or BSPCN_NOT, more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
    mod_state = get_mods();
#ifdef CONSOLE_ENABLE
    if (pressed) {
        combo_t *combo = &key_combos[combo_index];
        uint8_t idx = 0;
        uint16_t combo_keycode;
        while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
            uprintf("0x%04X,NA,NA,%u,%u,0x%02X,0x%02X,0\n",
                combo_keycode,
                /* <missing row information> */
                /* <missing column information> */
                get_highest_layer(layer_state),
                pressed,
                get_mods(),
                get_oneshot_mods()
            );
            idx++;
        }
    }
#endif
    switch(combo_index) {

        case UYCLN_INDEX:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("[1]");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("[0]");
                    set_mods(mod_state);
                }
                else {
                    send_string("[i]");
                }
        }
        break;

        case JU_JUST:
        steno_combo("just", "Just", NULL, pressed, mod_state);
        break;

        case HV_HAVE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Have");
                    set_mods(mod_state);
                }
                else {
                    send_string("have");
                }
        }
        break;

        case QK_QMK:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    send_string("QMK");
                    set_mods(mod_state);
                }
                else {
                    send_string("qmk");
                }
        }
        break;

        case BSPCEV_EVERY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Every");
                    set_mods(mod_state);
                }
                else {
                    send_string("every");
                }
        }
        break;

        case BSPCU_YOU:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("You");
                    set_mods(mod_state);
                }
                else {
                    send_string("you");
                }
        }
        break;

        case BSPCA_AND:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("And");
                    set_mods(mod_state);
                }
                else {
                    send_string("and");
                }
        }
        break;

        case BSPCN_NOT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Not");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("n't");
                    set_mods(mod_state);
                }
                else {
                    send_string("not");
                }
        }
        break;

        case BSPCW_WITH:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("With");
                    set_mods(mod_state);
                }
                else {
                    send_string("with");
                }
        }
        break;

        case BSPCF_FOR:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("For");
                    set_mods(mod_state);
                }
                else {
                    send_string("for");
                }
        }
        break;

        case BSPCH_HERE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Here");
                    set_mods(mod_state);
                }
                else {
                    send_string("here");
                }
        }
        break;

        case BSPCT_THE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("The");
                    set_mods(mod_state);
                }
                else {
                    send_string("the");
                }
        }
        break;

        case BSPCM_MENT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ment");
                    set_mods(mod_state);
                }
                else {
                    send_string("ment");
                }
        }
        break;

        case BSPCG_ING:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ing");
                    set_mods(mod_state);
                }
                else {
                    send_string("ing");
                }
        }
        break;

        case BSPCO_OUGH:
            if (pressed) {
                if (mod_state & MOD_MASK_CTRL) {
                    del_mods(MOD_MASK_CTRL);
                    send_string("ould");
                    set_mods(mod_state);
                }
                else if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ough");
                    set_mods(mod_state);
                }
                else {
                    send_string("ough");
                }
        }
        break;

        case BSPCI_ION:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ion");
                    set_mods(mod_state);
                }
                else {
                    send_string("ion");
                }
        }
        break;

        case BSPCIS_IONS:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Ions");
                    set_mods(mod_state);
                }
                else {
                    send_string("ions");
                }
        }
        break;

        case BSPCTA_THAT:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("That");
                    set_mods(mod_state);
                }
                else {
                    send_string("that");
                }
        }
        break;

        case BSPCQ_QUE:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Que");
                    set_mods(mod_state);
                }
                else {
                    send_string("que");
                }
        }
        break;

        case BSPCK_KEY:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Key");
                    set_mods(mod_state);
                }
                else {
                    send_string("key");
                }
        }
        break;

        case KB_KEYBOARD:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    send_string("Keyboard");
                    set_mods(mod_state);
                }
                else {
                    send_string("keyboard");
                }
        }
        break;

        case WA_WHAT:
            steno_combo("what", "What", NULL, pressed, mod_state);
        break;

        case BSPCTS_THIS:
            steno_combo("this", "This", NULL, pressed, mod_state);
        break;

        case BSPCDN_DONT:
            steno_combo("don't", "Don't", NULL, pressed, mod_state);
        break;

        case BSPCIT_IN_THE:
            steno_combo("in the", "In the", NULL, pressed, mod_state);
        break;

        case DOTSLASH_UPDIR:
            if (pressed) {
                send_string("../");
            }
        break;
    }
};

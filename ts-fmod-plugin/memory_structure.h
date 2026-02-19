#pragma once

#include "prism/collections/array_dyn.h"
#include "prism/collections/list_dyn.h"
#include "prism/collections/array_local.h"
#include "prism/string.h"

using namespace ts_fmod_plugin::prism;

#pragma pack( push, 1 )

struct vec2s_t // Size: 0x0008
{
public:
    float x; // 0x0000 (0x04)
    float y; // 0x0004 (0x04)
};

struct vec3s_t // Size: 0x000C
{
public:
    float x; // 0x0000 (0x04)
    float y; // 0x0004 (0x04)
    float z; // 0x0008 (0x04)
};

struct vec4s_t // Size: 0x0010
{
public:
    float w; // 0x0000 (0x04)
    float x; // 0x0004 (0x04)
    float y; // 0x0008 (0x04)
    float z; // 0x000C (0x04)
};

struct token_t // Size: 0x0008
{
    uint64_t token; // 0x0000 (0x08)
};

class unit_t // Size: 0x0010
{
public:
    void* vtable;   // 0x0000 (0x08)
    uint32_t unk;   // 0x0008 (0x04)
    uint32_t unk_2; // 0x000C (0x04)
};

static_assert(sizeof(unit_t) == 0x10);

class placement_t // Size: 0x0020
{
public:
    vec3s_t pos;  // 0x0000 (0x0c)
    int16_t cx;   // 0x000C (0x02)
    int16_t cz;   // 0x000E (0x02)
    vec4s_t rot;  // 0x0010 (0x10)
};
static_assert( sizeof( placement_t ) == 0x20 );


// Size: 0x23D8
class game_actor_u : public /* [0x10] @ 0x00 */ unit_t
{
public:
    char pad_0010[ 8 ]; // 0x0010 (0x08)
    class game_physics_vehicle_u *game_physics_vehicle; // 0x0018 (0x08)
    class visual_interior_u* visual_interior;           // 0x0020 (0x08)
    class N0000F213* N0000F1FD;                         // 0x0028 (0x08)
    class game_actor_hud_u* game_actor_hud;             // 0x0030 (0x08)
    char pad_0038[ 24 ]; // 0x0038 (0x18)
    bool stored_show_weigh; // 0x0050 (0x01)
    bool stored_need_to_weigh; // 0x0051 (0x01)
    char pad_0052[ 86 ]; // 0x0052 (0x56)
    class history_stream_set_u* history_stream_set; // 0x00A8 (0x08)
    char pad_00B0[ 16 ]; // 0x00B0 (0x10)
    class history_manager_u* history_manager;       // 0x00C0 (0x08)
    class game_trailer_actor_u* game_trailer_actor; // 0x00C8 (0x08)
    char pad_00D0[ 116 ]; // 0x00D0 (0x74)
    uint32_t current_camera; // 0x0144 (0x04) 2 = int, 1 = chase, 7 = top, 5 = roof, 4 = side_back, 3 = hood, 6 = side_front, 9 = cinematic, 0 = dev
    char pad_0148[ 8 ]; // 0x0148 (0x08)
    uint32_t engine_state; // 0x0150 (0x04) 0 = engine off, 1 = starting, 2 = running, 3 = shutting down
    bool ignition; // 0x0154 (0x01)
    char pad_0155[ 7 ]; // 0x0155 (0x07)
    bool parking_brake; // 0x015C (0x01)
    char pad_015D[ 9 ]; // 0x015D (0x09)
    bool engine_brake_enabled; // 0x0166 (0x01)
    char pad_0167[ 25 ]; // 0x0167 (0x19)
    uint32_t retarder_i_level; // 0x0180 (0x04)
    float retarder_f_level; // 0x0184 (0x04)
    char pad_0188[ 4 ]; // 0x0188 (0x04)
    bool diff_locked; // 0x018C (0x01)
    char pad_018D[ 12 ]; // 0x018D (0x0c)
    bool cruise_control_enabled; // 0x0199 (0x01)
    char pad_019A[ 2 ]; // 0x019A (0x02)
    float cruise_control_speed; // 0x019C (0x04)
    char pad_01A0[ 32 ]; // 0x01A0 (0x20)
    uint32_t wiper_setting; // 0x01C0 (0x04)
    char pad_01C4[ 24 ]; // 0x01C4 (0x18)
    uint16_t flags; // 0x01DC (0x02) 6 = parking lights, 8 = low beam, 7 = high beam, 5 = beacons, 0 = truck axle lifted, 1 = trailer axle lifted
    char pad_01DE[ 2 ]; // 0x01DE (0x02)
    uint16_t additional_illumination; // 0x01E0 (0x02) (flags) 3 = front, 4 = roof
    char pad_01E2[ 14 ]; // 0x01E2 (0x0e)
    float wipers_intermittent_time; // 0x01F0 (0x04)
    float wipers_position; // 0x01F4 (0x04)
    char pad_01F8[ 8 ]; // 0x01F8 (0x08)
    array_local_t<  float, 7ul > N0000F539; // 0x0200 (0x3c)
    char pad_023C[ 4 ]; // 0x023C (0x04)
    array_local_t<  float, 7ul > N0000F541; // 0x0240 (0x3c)
    char pad_027C[ 4 ]; // 0x027C (0x04)
    array_local_t<  float, 3ul > N0000F549; // 0x0280 (0x2c)
    char pad_02AC[ 4 ]; // 0x02AC (0x04)
    array_local_t<  float, 3ul > N0000F54F; // 0x02B0 (0x2c)
    char pad_02DC[ 8 ]; // 0x02DC (0x08)
    float rpm; // 0x02E4 (0x04)
    float air_pressure; // 0x02E8 (0x04)
    float brake_pressure; // 0x02EC (0x04)
    float max_air_pressure; // 0x02F0 (0x04)
    char pad_02F4[ 8 ]; // 0x02F4 (0x08)
    float oil_temp; // 0x02FC (0x04)
    char pad_0300[ 4 ]; // 0x0300 (0x04)
    float water_temp; // 0x0304 (0x04)
    char pad_0308[ 4 ]; // 0x0308 (0x04)
    float battery_voltage; // 0x030C (0x04)
    char pad_0310[ 8 ]; // 0x0310 (0x08)
    float turbo_pressure; // 0x0318 (0x04)
    char pad_031C[ 16 ]; // 0x031C (0x10)
    float light_switch; // 0x032C (0x04) 0 = off, 0.5 = parking, 1 = low beam
    float light_switch_state; // 0x0330 (0x04) 0 = off, 0.5 = parking, 1 = low beam (instant)
    float high_beam_stick; // 0x0334 (0x04) 0 = off, 1 = on
    float high_beam_state; // 0x0338 (0x04) 0 = off, 1 = on (instant)
    float light_horn_stick; // 0x033C (0x04) 0 = off, 1 = on
    float light_horn_state; // 0x0340 (0x04) 0 = off, 1 = on (instant)
    float indicator_stick; // 0x0344 (0x04) 0 = left indicator, 0.5 = none, 1 = right
    float indicator_state; // 0x0348 (0x04) 0 = left indicator, 0.5 = none, 1 = right (instant)
    float hazard_warning_btn; // 0x034C (0x04) 0 = off, 1 = on
    float hazard_warning_state; // 0x0350 (0x04) 0 = off, 1 = on (instant)
    float beacon_switch; // 0x0354 (0x04) 0 = off, 1 = on
    float beacon_state; // 0x0358 (0x04) 0 = off, 1 = on (instant)
    char pad_035C[ 8 ]; // 0x035C (0x08)
    float handbrake_handle; // 0x0364 (0x04) 0 = off, 1 = on
    float handbrake_state; // 0x0368 (0x04) 0 = off, 1 = on (instant)
    char pad_036C[ 24 ]; // 0x036C (0x18)
    float engine_brake_stick; // 0x0384 (0x04) 0 = off, 1 = full; steps dependant on engine data
    float engine_brake_state; // 0x0388 (0x04) 0 = off, 1 = full (instant); steps dependant on engine data
    char pad_038C[ 20 ]; // 0x038C (0x14)
    float wipers_stick; // 0x03A0 (0x04) 0 = off, 0.333 = intermittent, 0.666 = slow, 1 = fast
    float wipers_state; // 0x03A4 (0x04) 0 = off, 0.333 = intermittent, 0.666 = slow, 1 = fast (instant)
    char pad_03A8[ 20 ]; // 0x03A8 (0x14)
    uint8_t left_window_moving_direction; // 0x03BC (0x01) 1 = got to end down; 2 = got to end up; 16 = down; 32 = up
    uint8_t is_left_window_moving; // 0x03BD (0x01) 1 = down auto; 16 = down holding btn; 2 = auto up; 32 = up holding button
    char pad_03BE[ 2 ]; // 0x03BE (0x02)
    float left_window_state; // 0x03C0 (0x04) 0 = up; 1 = down
    float left_window_btn; // 0x03C4 (0x04) 0 = up; 0.5 off; 1 = down
    float left_window_btn_state; // 0x03C8 (0x04) 0 = up; 0.5 off; 1 = down (instant)
    char pad_03CC[ 8 ]; // 0x03CC (0x08)
    uint8_t right_window_moving_direction; // 0x03D4 (0x01) 1 = got to end down; 2 = got to end up; 16 = down; 32 = up
    uint8_t is_right_window_moving; // 0x03D5 (0x01) 1 = down auto; 16 = down holding btn; 2 = auto up; 32 = up holding button
    char pad_03D6[ 2 ]; // 0x03D6 (0x02)
    float right_window_state; // 0x03D8 (0x04) 0 = up; 1 = down
    float right_window_btn; // 0x03DC (0x04) 0 = up; 0.5 off; 1 = down
    float right_window_btn_state; // 0x03E0 (0x04) 0 = up; 0.5 off; 1 = down (instant)
    char pad_03E4[ 6288 ]; // 0x03E4 (0x1890)
    float rpm2; // 0x1C74 (0x04)
    float some_throttle; // 0x1C78 (0x04) or something like it
    char pad_1C7C[ 12 ]; // 0x1C7C (0x0c)
    float throttle_input; // 0x1C88 (0x04) truck.input.throttle
    float brake_input; // 0x1C8C (0x04) truck.input.brake
    float clutch_input; // 0x1C90 (0x04) truck.input.clutch
    char pad_1C94[ 4 ]; // 0x1C94 (0x04)
    float steering_input; // 0x1C98 (0x04)
    char pad_1C9C[ 48 ]; // 0x1C9C (0x30)
    placement_t placement; // 0x1CCC (0x20)
    char pad_1CEC[ 12 ]; // 0x1CEC (0x0c)
    class model_object_u* driver_model;                       // 0x1CF8 (0x08)
    char pad_1D00[ 24 ]; // 0x1D00 (0x18)
    class physics_gearbox_sequential_u* physics_gearbox_sequential; // 0x1D18 (0x08)
    class physics_gearbox_automatic_u* physics_gearbox_automatic;   // 0x1D20 (0x08)
    class physics_gearbox_direct_u* physics_gearbox_direct;         // 0x1D28 (0x08)
    char pad_1D30[ 8 ]; // 0x1D30 (0x08)
    class accessory_head_lights_data_u* accessory_head_lights_data; // 0x1D38 (0x08)
    char pad_1D40[ 1688 ]; // 0x1D40 (0x698)

public:
    float get_light_switch_state() const
    {
        return light_switch_state;
    }

    float get_light_horn_state() const
    {
        return light_horn_state;
    }

    float get_hazard_warning_state() const
    {
        return hazard_warning_state;
    }

    float get_wipers_state() const
    {
        return wipers_state;
    }

    float get_turbo_pressure() const
    {
        return turbo_pressure;
    }

    uint32_t get_engine_state() const
    {
        return engine_state;
    }

    float get_wiper_position() const
    {
        return wipers_position;
    }

    float get_engine_brake_state() const
    {
        return engine_brake_state;
    }
};
static_assert( sizeof( game_actor_u ) == 0x23D8 );

// Size: 0x0010
class sound_event_t
{
public:
    class fmod_event_t* fmod_sound_event; // 0x0008 (0x08)

    virtual void destructor();
};
static_assert(sizeof(sound_event_t) == 0x10);

class voice_navigation_sound_t
{
    uint32_t pad_0000;   // 0x0000 (0x04)
    uint32_t pad_0004;   // 0x0004 (0x04)
    char* event_name;    // 0x0008 (0x08)
    uint32_t pad_0010;   // 0x0010 (0x04)
    uint32_t pad_0014;   // 0x0014 (0x04)
    sound_event_t event; // 0x0018 (0x10)

public:

    const char* get_event_name() const
    {
        return event_name;
    }
};

namespace sound
{
    // Size: 0x0008
    class sound_owner_t
    {
    public:
        virtual void destructor();
    };
    static_assert( sizeof( sound_owner_t ) == 0x8 );

    // Size: 0x0008
    class sound_base_t : public /* [0x08] @ 0x00 */ sound_owner_t
    {
    public:
    };
    static_assert( sizeof( sound_base_t ) == 0x8 );

    // Size: 0x0010
    class sound_stream_t : public /* [0x08] @ 0x00 */ sound_base_t
    {
    public:
        class fmod_stream_t* stream; // 0x0008 (0x08)
    };
    static_assert( sizeof( sound_stream_t ) == 0x10 );
}

// Size: 0x1F70 1.58
class sound_library_t
{
public:
    char pad_0008[ 8 ]; // 0x0008 (0x08)
    array_local_t< class sound_event_t*, 30ul > ui_sound_events; // 0x0010 (0x110)
    char pad_0120[ 12 ]; // 0x0120 (0x0c)
    uint32_t state; // 0x012C (0x04) 1 = on; 2 = off
    bool interior_camera; // 0x0130 (0x01)
    bool is_camera_inside; // 0x0131 (0x01)
    char pad_0132[ 2 ]; // 0x0132 (0x02)
    float camera_rotation_in_cabin; // 0x0134 (0x04)
    float cabin_out; // 0x0138 (0x04)
    char pad_013C[ 4 ]; // 0x013C (0x04)
    class fmod_parameter_t* cabin_type_param; // 0x0140 (0x08)
    class fmod_parameter_t* cabin_rot_param; // 0x0148 (0x08)
    class fmod_parameter_t* cabin_out_param; // 0x0150 (0x08)
    vec2s_t window_state; // 0x0158 (0x08)
    class fmod_parameter_t* wnd_left_param; // 0x0160 (0x08)
    class fmod_parameter_t* wnd_right_param; // 0x0168 (0x08)
    float daytime; // 0x0170 (0x04)
    char pad_0174[ 4 ]; // 0x0174 (0x04)
    class fmod_parameter_t* daytime_param; // 0x0178 (0x08)
    char pad_0180[ 48 ]; // 0x0180 (0x30)
    array_local_t< class voice_navigation_sound_t, 38ul > navigation_sounds; // 0x01B0 (0x610)
    string_dyn_t current_navigation_bank_path; // 0x07C0 (0x18)
    voice_navigation_sound_t* now_playing_navigation_sound; // 0x07D8 (0x08)
    list_dyn_t< class voice_navigation_sound_t* > N0000433C; // 0x07E0 (0x58)
    array_dyn_t< class voice_navigation_sound_t* > navigation_sound_events; // 0x0838 (0x20)
    char pad_0858[ 5144 ]; // 0x0858 (0x1418)
    bool should_have_echo; // 0x1C70 (0x01)
    char pad_1C71[ 223 ]; // 0x1C71 (0xdf)
    array_local_t< class sound_event_t*, 20ul > N0000D549; // 0x1D50 (0xc0)
    char pad_1E10[ 8 ]; // 0x1E10 (0x08)
    array_local_t< sound::sound_stream_t, 1ul > N0000D565; // 0x1E18 (0x30)
    array_local_t< bool, 1ul > N0001ADE2; // 0x1E48 (0x21)
    char pad_1E69[ 7 ]; // 0x1E69 (0x07)
    sound_event_t cb_radio_start; // 0x1E70 (0x10)
    sound_event_t cb_radio_stop; // 0x1E80 (0x10)
    sound_event_t cb_radio_noise; // 0x1E90 (0x10)
    array_dyn_t< class cbradio_beep_item_t* > N0000D574; // 0x1EA0 (0x20)
    char pad_1EC0[ 16 ]; // 0x1EC0 (0x10)
    array_local_t< string_dyn_t, 3ul > ambient_sounds; // 0x1ED0 (0x68)
    string_dyn_t current_reverb; // 0x1F38 (0x18)
    string_dyn_t current_ambient_sfx; // 0x1F50 (0x18)
    char pad_1F68[ 8 ]; // 0x1F68 (0x08)

    virtual void destructor();

public:
    uint8_t get_has_echo() const
    {
        return should_have_echo;
    }

    vec2s_t get_window_state() const
    {
        return window_state;
    }

    bool get_is_camera_inside() const
    {
        return is_camera_inside;
    }

    bool get_is_on_interior_cam() const
    {
        return interior_camera;
    }

    float get_camera_rotation_in_cabin() const
    {
        return camera_rotation_in_cabin;
    }

    bool get_cabin_out() const
    {
        return cabin_out;
    }

    voice_navigation_sound_t* get_now_playing_navigation_sound() const
    {
        return now_playing_navigation_sound;
    }
};
static_assert( sizeof( sound_library_t ) == 0x1F70 );

#pragma pack( pop )

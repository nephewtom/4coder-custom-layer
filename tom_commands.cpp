#define CHEATSHEET_TXT_FILE "C:\\4coder\\custom\\tom\\bindings_cheatsheet.txt"

CUSTOM_COMMAND_SIG(open_cheatsheet)
CUSTOM_DOC("Open cheatsheet.")
{
    change_active_panel(app);
    View_ID view = get_active_view(app, Access_ReadVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);
    if(buffer_exists(app, buffer)) {
        // TODO make the buffer read-only
        view_open_file(app, view, string_u8_litexpr(CHEATSHEET_TXT_FILE), false);
    }
    change_active_panel(app);
}

CUSTOM_COMMAND_SIG(close_other_panels)
CUSTOM_DOC("Close other panels except current one.")
{
    View_ID my_view = get_active_view(app, Access_Always);
    Buffer_ID buffer = view_get_buffer(app, my_view, Access_ReadVisible);    
    if(buffer_exists(app, buffer)) { ; }
    change_active_panel(app);
    
    View_ID other_view = 0;
    while (my_view != other_view) {
        other_view = get_active_view(app, Access_Always);
        view_close(app, other_view);
    }
    //Panel_ID panel = view_get_panel(app, other_view);
    //if (panel == 0) {;}
} 

CUSTOM_COMMAND_SIG(switch_to_previos_buffer)
CUSTOM_DOC("Switch to previous buffer.")
{
    View_ID view = get_view_for_locked_jump_buffer(app);
    if (view) {}
}

// TODO(TOM): Study how to do this... 
// TODO(TOM): 1) How to write messages on *log* buffer?
// TODO(TOM): 2) Ask in Discord...
CUSTOM_COMMAND_SIG(kill_line)
CUSTOM_DOC("Emulate Emacs kill-line C-k.")
{
    View_ID view = get_active_view(app, Access_ReadWriteVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);
    i64 pos = view_get_cursor_pos(app, view);
    i64 line = get_line_number_from_pos(app, buffer, pos);
    Range_i64 range = get_line_pos_range(app, buffer, line);
    range.end += 1;
    i32 size = (i32)buffer_get_size(app, buffer);
    range.end = clamp_top(range.end, size);
    if (range_size(range) == 0 ||
        buffer_get_char(app, buffer, range.end - 1) != '\n'){
        range.start -= 1;
        range.first = clamp_bot(0, range.first);
    }
    buffer_replace_range(app, buffer, range, string_u8_litexpr(""));
}
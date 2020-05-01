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

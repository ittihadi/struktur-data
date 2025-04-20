#!/usr/bin/env sh

# Launch kitty with settings that mimic stock Windows CMD / Windows Terminal
# with extra padding to make screenshots easier

kitty -o background_opacity=1 -o font_size=12 \
      -o font_family="Fira Code" \
      -o bold_font="Fira Code" \
      -o italic_font="Fira Code" \
      -o bold_italic_font="Fira Code" \
      -o background="#0C0C0C" -o foreground="#CCCCCC" \
      -o window_margin_width="8 12" \
      -o font_features="FiraCode-Regular +zero -liga" \
      -o font_features="FiraCode-SemiBold +zero -liga" \
      -o font_features="FiraCode-Retina +zero -liga" \
      -o disable_ligatures="always" \
      -o scrollback_indicator_opacity=0


const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "06_01_TraverseDoublyLinkedList.c",
        "06_02_TambahDoublyLinkedList.c",
        "06_03_BacaDoublyLinkedList.c",
        "06_04_UpdateDoublyLinkedList.c",
        "06_05_HapusDoublyLinkedList.c",
        "06_06_01_SistemNavigasiRiwayatBrowser.c",
        "06_06_02_SistemManajemenPlaylistMusic.c",
    };

    const build_all_step = b.step("all", "Builds all files");

    inline for (files) |file| {
        const exe = b.addExecutable(.{
            .name = file[0 .. file.len - 2],
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        });

        exe.addCSourceFile(.{ .file = b.path(file) });
        b.installArtifact(exe);

        build_all_step.dependOn(&exe.step);
    }
}

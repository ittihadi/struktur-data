const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "07_01_TraverseCircDoublyLinkedList.c",
        "07_02_TambahCircDoublyLinkedList.c",
        "07_03_BacaCircDoublyLinkedList.c",
        "07_04_UpdateCircDoublyLinkedList.c",
        "07_05_HapusCircDoublyLinkedList.c",
        "07_06_01_SistemPemesananTikenBioskop.c",
        "07_06_02_SistemPengelolaTimOlahraga.c",
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

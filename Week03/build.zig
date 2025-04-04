const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "04_SinglyLinkedList_01_Traversal.c",
        "04_SinglyLinkedList_02_Add.c",
        "04_SinglyLinkedList_03_Read.c",
        "04_SinglyLinkedList_04_Update.c",
        "04_SinglyLinkedList_05_Delete.c",
        "04_SinglyLinkedList_06_01_Patient_Queue.c",
        "04_SinglyLinkedList_06_02_Library_Book_Management.c",
        "05_01_TraverseCircSinglyLinkedList.c",
        "05_02_TambahCircSinglyLinkedList.c",
        "05_03_BacaCircSinglyLinkedList.c",
        "05_04_UpdateCircSinglyLinkedList.c",
        "05_05_HapusCircSinglyLinkedList.c",
        "05_06_01_SistemPemesananMakananRestoran.c",
        "05_06_02_SistemPengelolaPemainPermainanGiliran.c",
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

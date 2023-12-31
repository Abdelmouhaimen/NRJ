pragma Warnings (Off);
pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__powerjoular.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__powerjoular.adb");
pragma Suppress (Overflow_Check);
with Ada.Exceptions;

package body ada_main is

   E074 : Short_Integer; pragma Import (Ada, E074, "system__os_lib_E");
   E010 : Short_Integer; pragma Import (Ada, E010, "ada__exceptions_E");
   E015 : Short_Integer; pragma Import (Ada, E015, "system__soft_links_E");
   E027 : Short_Integer; pragma Import (Ada, E027, "system__exception_table_E");
   E040 : Short_Integer; pragma Import (Ada, E040, "ada__containers_E");
   E069 : Short_Integer; pragma Import (Ada, E069, "ada__io_exceptions_E");
   E055 : Short_Integer; pragma Import (Ada, E055, "ada__strings_E");
   E057 : Short_Integer; pragma Import (Ada, E057, "ada__strings__maps_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__strings__maps__constants_E");
   E045 : Short_Integer; pragma Import (Ada, E045, "interfaces__c_E");
   E028 : Short_Integer; pragma Import (Ada, E028, "system__exceptions_E");
   E085 : Short_Integer; pragma Import (Ada, E085, "system__object_reader_E");
   E050 : Short_Integer; pragma Import (Ada, E050, "system__dwarf_lines_E");
   E023 : Short_Integer; pragma Import (Ada, E023, "system__soft_links__initialize_E");
   E039 : Short_Integer; pragma Import (Ada, E039, "system__traceback__symbolic_E");
   E221 : Short_Integer; pragma Import (Ada, E221, "ada__numerics_E");
   E113 : Short_Integer; pragma Import (Ada, E113, "ada__strings__utf_encoding_E");
   E119 : Short_Integer; pragma Import (Ada, E119, "ada__tags_E");
   E111 : Short_Integer; pragma Import (Ada, E111, "ada__strings__text_buffers_E");
   E176 : Short_Integer; pragma Import (Ada, E176, "gnat_E");
   E244 : Short_Integer; pragma Import (Ada, E244, "interfaces__c__strings_E");
   E109 : Short_Integer; pragma Import (Ada, E109, "ada__streams_E");
   E135 : Short_Integer; pragma Import (Ada, E135, "system__file_control_block_E");
   E134 : Short_Integer; pragma Import (Ada, E134, "system__finalization_root_E");
   E132 : Short_Integer; pragma Import (Ada, E132, "ada__finalization_E");
   E131 : Short_Integer; pragma Import (Ada, E131, "system__file_io_E");
   E195 : Short_Integer; pragma Import (Ada, E195, "system__storage_pools_E");
   E199 : Short_Integer; pragma Import (Ada, E199, "system__finalization_masters_E");
   E197 : Short_Integer; pragma Import (Ada, E197, "system__storage_pools__subpools_E");
   E163 : Short_Integer; pragma Import (Ada, E163, "ada__strings__unbounded_E");
   E188 : Short_Integer; pragma Import (Ada, E188, "system__regpat_E");
   E008 : Short_Integer; pragma Import (Ada, E008, "ada__calendar_E");
   E006 : Short_Integer; pragma Import (Ada, E006, "ada__calendar__delays_E");
   E217 : Short_Integer; pragma Import (Ada, E217, "ada__calendar__time_zones_E");
   E107 : Short_Integer; pragma Import (Ada, E107, "ada__text_io_E");
   E232 : Short_Integer; pragma Import (Ada, E232, "gnat__ctrl_c_E");
   E226 : Short_Integer; pragma Import (Ada, E226, "gnat__directory_operations_E");
   E179 : Short_Integer; pragma Import (Ada, E179, "gnat__string_split_E");
   E203 : Short_Integer; pragma Import (Ada, E203, "system__pool_global_E");
   E183 : Short_Integer; pragma Import (Ada, E183, "gnat__expect_E");
   E229 : Short_Integer; pragma Import (Ada, E229, "system__regexp_E");
   E224 : Short_Integer; pragma Import (Ada, E224, "gnat__command_line_E");
   E175 : Short_Integer; pragma Import (Ada, E175, "cpu_cycles_E");
   E181 : Short_Integer; pragma Import (Ada, E181, "cpu_stat_app_E");
   E211 : Short_Integer; pragma Import (Ada, E211, "cpu_stat_pid_E");
   E213 : Short_Integer; pragma Import (Ada, E213, "csv_power_E");
   E234 : Short_Integer; pragma Import (Ada, E234, "help_info_E");
   E236 : Short_Integer; pragma Import (Ada, E236, "intel_rapl_sysfs_E");
   E238 : Short_Integer; pragma Import (Ada, E238, "nvidia_smi_E");
   E240 : Short_Integer; pragma Import (Ada, E240, "os_utils_E");
   E246 : Short_Integer; pragma Import (Ada, E246, "raspberry_pi_cpu_formula_E");

   Sec_Default_Sized_Stacks : array (1 .. 1) of aliased System.Secondary_Stack.SS_Stack (System.Parameters.Runtime_Default_Sec_Stack_Size);

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
   begin
      E229 := E229 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "system__regexp__finalize_spec");
      begin
         F1;
      end;
      E183 := E183 - 1;
      declare
         procedure F2;
         pragma Import (Ada, F2, "gnat__expect__finalize_spec");
      begin
         F2;
      end;
      E203 := E203 - 1;
      declare
         procedure F3;
         pragma Import (Ada, F3, "system__pool_global__finalize_spec");
      begin
         F3;
      end;
      E107 := E107 - 1;
      declare
         procedure F4;
         pragma Import (Ada, F4, "ada__text_io__finalize_spec");
      begin
         F4;
      end;
      E163 := E163 - 1;
      declare
         procedure F5;
         pragma Import (Ada, F5, "ada__strings__unbounded__finalize_spec");
      begin
         F5;
      end;
      E197 := E197 - 1;
      declare
         procedure F6;
         pragma Import (Ada, F6, "system__storage_pools__subpools__finalize_spec");
      begin
         F6;
      end;
      E199 := E199 - 1;
      declare
         procedure F7;
         pragma Import (Ada, F7, "system__finalization_masters__finalize_spec");
      begin
         F7;
      end;
      declare
         procedure F8;
         pragma Import (Ada, F8, "system__file_io__finalize_body");
      begin
         E131 := E131 - 1;
         F8;
      end;
      declare
         procedure Reraise_Library_Exception_If_Any;
            pragma Import (Ada, Reraise_Library_Exception_If_Any, "__gnat_reraise_library_exception_if_any");
      begin
         Reraise_Library_Exception_If_Any;
      end;
   end finalize_library;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (Ada, s_stalib_adafinal, "system__standard_library__adafinal");

      procedure Runtime_Finalize;
      pragma Import (C, Runtime_Finalize, "__gnat_runtime_finalize");

   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      Runtime_Finalize;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;
   pragma Favor_Top_Level (No_Param_Proc);

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Default_Secondary_Stack_Size : System.Parameters.Size_Type;
      pragma Import (C, Default_Secondary_Stack_Size, "__gnat_default_ss_size");
      Bind_Env_Addr : System.Address;
      pragma Import (C, Bind_Env_Addr, "__gl_bind_env_addr");

      procedure Runtime_Initialize (Install_Handler : Integer);
      pragma Import (C, Runtime_Initialize, "__gnat_runtime_initialize");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
      Binder_Sec_Stacks_Count : Natural;
      pragma Import (Ada, Binder_Sec_Stacks_Count, "__gnat_binder_ss_count");
      Default_Sized_SS_Pool : System.Address;
      pragma Import (Ada, Default_Sized_SS_Pool, "__gnat_default_ss_pool");

   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;

      ada_main'Elab_Body;
      Default_Secondary_Stack_Size := System.Parameters.Runtime_Default_Sec_Stack_Size;
      Binder_Sec_Stacks_Count := 1;
      Default_Sized_SS_Pool := Sec_Default_Sized_Stacks'Address;

      Runtime_Initialize (1);

      Finalize_Library_Objects := finalize_library'access;

      Ada.Exceptions'Elab_Spec;
      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E027 := E027 + 1;
      Ada.Containers'Elab_Spec;
      E040 := E040 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E069 := E069 + 1;
      Ada.Strings'Elab_Spec;
      E055 := E055 + 1;
      Ada.Strings.Maps'Elab_Spec;
      E057 := E057 + 1;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E061 := E061 + 1;
      Interfaces.C'Elab_Spec;
      E045 := E045 + 1;
      System.Exceptions'Elab_Spec;
      E028 := E028 + 1;
      System.Object_Reader'Elab_Spec;
      E085 := E085 + 1;
      System.Dwarf_Lines'Elab_Spec;
      E050 := E050 + 1;
      System.Os_Lib'Elab_Body;
      E074 := E074 + 1;
      System.Soft_Links.Initialize'Elab_Body;
      E023 := E023 + 1;
      E015 := E015 + 1;
      System.Traceback.Symbolic'Elab_Body;
      E039 := E039 + 1;
      E010 := E010 + 1;
      Ada.Numerics'Elab_Spec;
      E221 := E221 + 1;
      Ada.Strings.Utf_Encoding'Elab_Spec;
      E113 := E113 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Tags'Elab_Body;
      E119 := E119 + 1;
      Ada.Strings.Text_Buffers'Elab_Spec;
      E111 := E111 + 1;
      Gnat'Elab_Spec;
      E176 := E176 + 1;
      Interfaces.C.Strings'Elab_Spec;
      E244 := E244 + 1;
      Ada.Streams'Elab_Spec;
      E109 := E109 + 1;
      System.File_Control_Block'Elab_Spec;
      E135 := E135 + 1;
      System.Finalization_Root'Elab_Spec;
      E134 := E134 + 1;
      Ada.Finalization'Elab_Spec;
      E132 := E132 + 1;
      System.File_Io'Elab_Body;
      E131 := E131 + 1;
      System.Storage_Pools'Elab_Spec;
      E195 := E195 + 1;
      System.Finalization_Masters'Elab_Spec;
      System.Finalization_Masters'Elab_Body;
      E199 := E199 + 1;
      System.Storage_Pools.Subpools'Elab_Spec;
      E197 := E197 + 1;
      Ada.Strings.Unbounded'Elab_Spec;
      E163 := E163 + 1;
      System.Regpat'Elab_Spec;
      E188 := E188 + 1;
      Ada.Calendar'Elab_Spec;
      Ada.Calendar'Elab_Body;
      E008 := E008 + 1;
      Ada.Calendar.Delays'Elab_Body;
      E006 := E006 + 1;
      Ada.Calendar.Time_Zones'Elab_Spec;
      E217 := E217 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E107 := E107 + 1;
      E232 := E232 + 1;
      Gnat.Directory_Operations'Elab_Spec;
      Gnat.Directory_Operations'Elab_Body;
      E226 := E226 + 1;
      Gnat.String_Split'Elab_Spec;
      E179 := E179 + 1;
      System.Pool_Global'Elab_Spec;
      E203 := E203 + 1;
      Gnat.Expect'Elab_Spec;
      E183 := E183 + 1;
      System.Regexp'Elab_Spec;
      E229 := E229 + 1;
      Gnat.Command_Line'Elab_Spec;
      Gnat.Command_Line'Elab_Body;
      E224 := E224 + 1;
      E175 := E175 + 1;
      E181 := E181 + 1;
      E211 := E211 + 1;
      E213 := E213 + 1;
      E234 := E234 + 1;
      E236 := E236 + 1;
      E238 := E238 + 1;
      E240 := E240 + 1;
      E246 := E246 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_powerjoular");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      if gnat_argc = 0 then
         gnat_argc := argc;
         gnat_argv := argv;
      end if;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/cpu_cycles.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/cpu_stat_app.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/cpu_stat_pid.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/csv_power.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/help_info.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/intel_rapl_sysfs.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/nvidia_smi.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/os_utils.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/raspberry_pi_cpu_formula.o
   --   /home/asarhane/Desktop/stagenrj/powerjoular/obj/powerjoular.o
   --   -L/home/asarhane/Desktop/stagenrj/powerjoular/obj/
   --   -L/home/asarhane/Desktop/stagenrj/powerjoular/obj/
   --   -L/usr/lib/gcc/x86_64-linux-gnu/12/adalib/
   --   -static
   --   -lgnat
   --   -ldl
--  END Object file/option list   

end ada_main;

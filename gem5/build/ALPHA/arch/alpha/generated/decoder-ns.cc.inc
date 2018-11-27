// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   alpha/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

    void
    AlphaStaticInst::printReg(std::ostream &os, int reg) const
    {
        if (reg < FP_Reg_Base) {
            ccprintf(os, "r%d", reg);
        }
        else {
            ccprintf(os, "f%d", reg - FP_Reg_Base);
        }
    }

    std::string
    AlphaStaticInst::generateDisassembly(Addr pc,
                                         const SymbolTable *symtab) const
    {
        std::stringstream ss;

        ccprintf(ss, "%-10s ", mnemonic);

        // just print the first two source regs... if there's
        // a third one, it's a read-modify-write dest (Rc),
        // e.g. for CMOVxx
        if (_numSrcRegs > 0) {
            printReg(ss, _srcRegIdx[0]);
        }
        if (_numSrcRegs > 1) {
            ss << ",";
            printReg(ss, _srcRegIdx[1]);
        }

        // just print the first dest... if there's a second one,
        // it's generally implicit
        if (_numDestRegs > 0) {
            if (_numSrcRegs > 0)
                ss << ",";
            printReg(ss, _destRegIdx[0]);
        }

        return ss.str();
    }

    std::string Nop::generateDisassembly(Addr pc,
                                         const SymbolTable *symtab) const
    {
#ifdef SS_COMPATIBLE_DISASSEMBLY
        return originalDisassembly;
#else
        return csprintf("%-10s (%s)", "nop", originalDisassembly);
#endif
    }

    std::string
    IntegerImm::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        std::stringstream ss;

        ccprintf(ss, "%-10s ", mnemonic);

        // just print the first source reg... if there's
        // a second one, it's a read-modify-write dest (Rc),
        // e.g. for CMOVxx
        if (_numSrcRegs > 0) {
            printReg(ss, _srcRegIdx[0]);
            ss << ",";
        }

        ss << (int)imm;

        if (_numDestRegs > 0) {
            ss << ",";
            printReg(ss, _destRegIdx[0]);
        }

        return ss.str();
    }

    int
    AlphaFP::getC99RoundingMode(uint64_t fpcr_val) const
    {
        if (roundingMode == Dynamic) {
            return alphaToC99RoundingMode[bits(fpcr_val, 59, 58)];
        }
        else {
            return alphaToC99RoundingMode[roundingMode];
        }
    }

    std::string
    AlphaFP::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        std::string mnem_str(mnemonic);

#ifndef SS_COMPATIBLE_DISASSEMBLY
        std::string suffix("");
        suffix += ((_destRegIdx[0] >= FP_Reg_Base)
                   ? fpTrappingModeSuffix[trappingMode]
                   : intTrappingModeSuffix[trappingMode]);
        suffix += roundingModeSuffix[roundingMode];

        if (suffix != "") {
            mnem_str = csprintf("%s/%s", mnemonic, suffix);
        }
#endif

        std::stringstream ss;
        ccprintf(ss, "%-10s ", mnem_str.c_str());

        // just print the first two source regs... if there's
        // a third one, it's a read-modify-write dest (Rc),
        // e.g. for CMOVxx
        if (_numSrcRegs > 0) {
            printReg(ss, _srcRegIdx[0]);
        }
        if (_numSrcRegs > 1) {
            ss << ",";
            printReg(ss, _srcRegIdx[1]);
        }

        // just print the first dest... if there's a second one,
        // it's generally implicit
        if (_numDestRegs > 0) {
            if (_numSrcRegs > 0)
                ss << ",";
            printReg(ss, _destRegIdx[0]);
        }

        return ss.str();
    }

    const int AlphaFP::alphaToC99RoundingMode[] = {
        M5_FE_TOWARDZERO,       // Chopped
        M5_FE_DOWNWARD, // Minus_Infinity
        M5_FE_TONEAREST,        // Normal
        M5_FE_UPWARD    // Dynamic in inst, Plus_Infinity in FPCR
    };

    const char *AlphaFP::roundingModeSuffix[] = { "c", "m", "", "d" };
    // mark invalid trapping modes, but don't fail on them, because
    // you could decode anything on a misspeculated path
    const char *AlphaFP::fpTrappingModeSuffix[] =
        { "", "u", "INVTM2", "INVTM3", "INVTM4", "su", "INVTM6", "sui" };
    const char *AlphaFP::intTrappingModeSuffix[] =
        { "", "v", "INVTM2", "INVTM3", "INVTM4", "sv", "INVTM6", "svi" };

    std::string
    Memory::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        return csprintf("%-10s %c%d,%d(r%d)", mnemonic,
                        flags[IsFloating] ? 'f' : 'r', RA, MEMDISP, RB);
    }

    std::string
    MemoryNoDisp::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        return csprintf("%-10s (r%d)", mnemonic, RB);
    }

    AlphaISA::PCState
    Branch::branchTarget(const AlphaISA::PCState &branchPC) const
    {
        return branchPC.pc() + 4 + disp;
    }

    AlphaISA::PCState
    Jump::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        uint64_t Rb = tc->readIntReg(_srcRegIdx[0]);
        pc.set((Rb & ~3) | (pc.pc() & 1));
        return pc;
    }

    const std::string &
    PCDependentDisassembly::disassemble(Addr pc,
                                        const SymbolTable *symtab) const
    {
        if (!cachedDisassembly ||
            pc != cachedPC || symtab != cachedSymtab)
        {
            if (cachedDisassembly)
                delete cachedDisassembly;

            cachedDisassembly =
                new std::string(generateDisassembly(pc, symtab));
            cachedPC = pc;
            cachedSymtab = symtab;
        }

        return *cachedDisassembly;
    }

    std::string
    Branch::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        std::stringstream ss;

        ccprintf(ss, "%-10s ", mnemonic);

        // There's only one register arg (RA), but it could be
        // either a source (the condition for conditional
        // branches) or a destination (the link reg for
        // unconditional branches)
        if (_numSrcRegs > 0) {
            printReg(ss, _srcRegIdx[0]);
            ss << ",";
        }
        else if (_numDestRegs > 0) {
            printReg(ss, _destRegIdx[0]);
            ss << ",";
        }

#ifdef SS_COMPATIBLE_DISASSEMBLY
        if (_numSrcRegs == 0 && _numDestRegs == 0) {
            printReg(ss, 31);
            ss << ",";
        }
#endif

        Addr target = pc + 4 + disp;

        std::string str;
        if (symtab && symtab->findSymbol(target, str))
            ss << str;
        else
            ccprintf(ss, "0x%x", target);

        return ss.str();
    }

    std::string
    Jump::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        std::stringstream ss;

        ccprintf(ss, "%-10s ", mnemonic);

#ifdef SS_COMPATIBLE_DISASSEMBLY
        if (_numDestRegs == 0) {
            printReg(ss, 31);
            ss << ",";
        }
#endif

        if (_numDestRegs > 0) {
            printReg(ss, _destRegIdx[0]);
            ss << ",";
        }

        ccprintf(ss, "(r%d)", RB);

        return ss.str();
    }

    std::string
    EmulatedCallPal::generateDisassembly(Addr pc,
                                         const SymbolTable *symtab) const
    {
#ifdef SS_COMPATIBLE_DISASSEMBLY
        return csprintf("%s %s", "call_pal", mnemonic);
#else
        return csprintf("%-10s %s", "call_pal", mnemonic);
#endif
    }

    inline
    CallPalBase::CallPalBase(const char *mnem, ExtMachInst _machInst,
                             OpClass __opClass)
        : AlphaStaticInst(mnem, _machInst, __opClass),
        palFunc(PALFUNC)
    {
        // From the 21164 HRM (paraphrased):
        // Bit 7 of the function code (mask 0x80) indicates
        // whether the call is privileged (bit 7 == 0) or
        // unprivileged (bit 7 == 1).  The privileged call table
        // starts at 0x2000, the unprivielged call table starts at
        // 0x3000.  Bits 5-0 (mask 0x3f) are used to calculate the
        // offset.
        const int palPrivMask = 0x80;
        const int palOffsetMask = 0x3f;

        // Pal call is invalid unless all other bits are 0
        palValid = ((machInst & ~(palPrivMask | palOffsetMask)) == 0);
        palPriv = ((machInst & palPrivMask) == 0);
        int shortPalFunc = (machInst & palOffsetMask);
        // Add 1 to base to set pal-mode bit
        palOffset = (palPriv ? 0x2001 : 0x3001) + (shortPalFunc << 6);
    }

    std::string
    CallPalBase::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        return csprintf("%-10s %#x", "call_pal", palFunc);
    }

    inline
    HwLoadStore::HwLoadStore(const char *mnem, ExtMachInst _machInst,
                             OpClass __opClass)
        : Memory(mnem, _machInst, __opClass), disp(HW_LDST_DISP)
    {
        memAccessFlags.clear();
        if (HW_LDST_PHYS) memAccessFlags.set(Request::PHYSICAL);
        if (HW_LDST_ALT)  memAccessFlags.set(Request::ALTMODE);
        if (HW_LDST_VPTE) memAccessFlags.set(Request::VPTE);
        if (HW_LDST_LOCK) memAccessFlags.set(Request::LLSC);
    }

    std::string
    HwLoadStore::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
#ifdef SS_COMPATIBLE_DISASSEMBLY
        return csprintf("%-10s r%d,%d(r%d)", mnemonic, RA, disp, RB);
#else
        // HW_LDST_LOCK and HW_LDST_COND are the same bit.
        const char *lock_str =
            (HW_LDST_LOCK) ? (flags[IsLoad] ? ",LOCK" : ",COND") : "";

        return csprintf("%-10s r%d,%d(r%d)%s%s%s%s%s",
                        mnemonic, RA, disp, RB,
                        HW_LDST_PHYS ? ",PHYS" : "",
                        HW_LDST_ALT ? ",ALT" : "",
                        HW_LDST_QUAD ? ",QUAD" : "",
                        HW_LDST_VPTE ? ",VPTE" : "",
                        lock_str);
#endif
    }

    std::string
    HwMoveIPR::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        if (_numSrcRegs > 0) {
            // must be mtpr
            return csprintf("%-10s r%d,IPR(%#x)",
                            mnemonic, RA, ipr_index);
        }
        else {
            // must be mfpr
            return csprintf("%-10s IPR(%#x),r%d",
                            mnemonic, ipr_index, RA);
        }
    }

    std::string
    OpcdecFault::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        return csprintf("%-10s (inst 0x%x, opcode 0x%x)",
                        " OPCDEC fault", machInst, OPCODE);
    }

    std::string
    FailUnimplemented::generateDisassembly(Addr pc,
                                           const SymbolTable *symtab) const
    {
        return csprintf("%-10s (unimplemented)", mnemonic);
    }

    std::string
    WarnUnimplemented::generateDisassembly(Addr pc,
                                           const SymbolTable *symtab) const
    {
#ifdef SS_COMPATIBLE_DISASSEMBLY
        return csprintf("%-10s", mnemonic);
#else
        return csprintf("%-10s (unimplemented)", mnemonic);
#endif
    }

    std::string
    Unknown::generateDisassembly(Addr pc, const SymbolTable *symtab) const
    {
        return csprintf("%-10s (inst 0x%x, opcode 0x%x)",
                        "unknown", machInst, OPCODE);
    }

// LoadAddress::lda([' Ra = Rb + disp; '],{})

    Lda::Lda(ExtMachInst machInst)
         : MemoryDisp32("lda", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;;
    }

// LoadAddress::ldah([' Ra = Rb + (disp << 16); '],{})

    Ldah::Ldah(ExtMachInst machInst)
         : MemoryDisp32("ldah", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;;
    }

// LoadOrNop::ldbu([' Ra_uq = Mem_ub; '],{})

    Ldbu::Ldbu(ExtMachInst machInst)
         : MemoryDisp32("ldbu", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

// LoadOrNop::ldwu([' Ra_uq = Mem_uw; '],{})

    Ldwu::Ldwu(ExtMachInst machInst)
         : MemoryDisp32("ldwu", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

// LoadOrNop::ldq_u([' Ra = Mem_uq; '],{'ea_code': ' EA = (Rb + disp) & ~7; '})

    Ldq_u::Ldq_u(ExtMachInst machInst)
         : MemoryDisp32("ldq_u", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

// LoadOrNop::ldt([' Fa = Mem_df; '],{})

    Ldt::Ldt(ExtMachInst machInst)
         : MemoryDisp32("ldt", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = FA + FP_Reg_Base;
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

// LoadOrNop::ldl_l([' Ra_sl = Mem_sl; '],{'mem_flags': 'LLSC'})

    Ldl_l::Ldl_l(ExtMachInst machInst)
         : MemoryDisp32("ldl_l", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	memAccessFlags = Request::LLSC;;
    }

// LoadOrNop::ldq_l([' Ra_uq = Mem_uq; '],{'mem_flags': 'LLSC'})

    Ldq_l::Ldq_l(ExtMachInst machInst)
         : MemoryDisp32("ldq_l", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	memAccessFlags = Request::LLSC;;
    }

// LoadOrPrefetch::ldl([' Ra_sl = Mem_sl; '],{})

    Ldl::Ldl(ExtMachInst machInst)
         : MemoryDisp32("ldl", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

    LdlPrefetch::LdlPrefetch(ExtMachInst machInst)
         : MemoryDisp32("ldl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	memAccessFlags = Request::PREFETCH;;
    }

// LoadOrPrefetch::ldq([' Ra_uq = Mem_uq; '],{'pf_flags': 'EVICT_NEXT'})

    Ldq::Ldq(ExtMachInst machInst)
         : MemoryDisp32("ldq", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

    LdqPrefetch::LdqPrefetch(ExtMachInst machInst)
         : MemoryDisp32("ldq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	memAccessFlags = Request::EVICT_NEXT|Request::PREFETCH;;
    }

// LoadOrPrefetch::lds([' Fa_uq = s_to_t(Mem_ul); '],{'pf_flags': 'PF_EXCLUSIVE', 'inst_flags': 'IsFloating'})

    Lds::Lds(ExtMachInst machInst)
         : MemoryDisp32("lds", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = FA + FP_Reg_Base;
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;;
    }

    LdsPrefetch::LdsPrefetch(ExtMachInst machInst)
         : MemoryDisp32("lds", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	memAccessFlags = Request::PF_EXCLUSIVE|Request::PREFETCH;;
    }

// Store::stb([' Mem_ub = Ra<7:0>; '],{})

    Stb::Stb(ExtMachInst machInst)
         : MemoryDisp32("stb", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::stw([' Mem_uw = Ra<15:0>; '],{})

    Stw::Stw(ExtMachInst machInst)
         : MemoryDisp32("stw", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::stl([' Mem_ul = Ra<31:0>; '],{})

    Stl::Stl(ExtMachInst machInst)
         : MemoryDisp32("stl", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::stq([' Mem_uq = Ra_uq; '],{})

    Stq::Stq(ExtMachInst machInst)
         : MemoryDisp32("stq", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::stq_u([' Mem_uq = Ra_uq; ', ' EA = (Rb + disp) & ~7; '],{})

    Stq_u::Stq_u(ExtMachInst machInst)
         : MemoryDisp32("stq_u", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::sts([' Mem_ul = t_to_s(Fa_uq); '],{})

    Sts::Sts(ExtMachInst machInst)
         : MemoryDisp32("sts", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// Store::stt([' Mem_df = Fa; '],{})

    Stt::Stt(ExtMachInst machInst)
         : MemoryDisp32("stt", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;;
    }

// StoreCond::stl_c([' Mem_ul = Ra<31:0>; ', '\n                        uint64_t tmp = write_result;\n                        // see stq_c\n                        Ra = (tmp == 0 || tmp == 1) ? tmp : Ra;\n                        if (tmp == 1) {\n                            xc->setStCondFailures(0);\n                        }\n                    '],{'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'})

    Stl_c::Stl_c(ExtMachInst machInst)
         : MemoryDisp32("stl_c", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = Request::LLSC;;
    }

// StoreCond::stq_c([' Mem_uq = Ra; ', "\n                        uint64_t tmp = write_result;\n                        // If the write operation returns 0 or 1, then\n                        // this was a conventional store conditional,\n                        // and the value indicates the success/failure\n                        // of the operation.  If another value is\n                        // returned, then this was a Turbolaser\n                        // mailbox access, and we don't update the\n                        // result register at all.\n                        Ra = (tmp == 0 || tmp == 1) ? tmp : Ra;\n                        if (tmp == 1) {\n                            // clear failure counter... this is\n                            // non-architectural and for debugging\n                            // only.\n                            xc->setStCondFailures(0);\n                        }\n                    "],{'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'})

    Stq_c::Stq_c(ExtMachInst machInst)
         : MemoryDisp32("stq_c", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = Request::LLSC;;
    }

// IntegerOperate::addl([' Rc_sl = Ra_sl + Rb_or_imm_sl; '],{})

    Addl::Addl(ExtMachInst machInst)
         : AlphaStaticInst("addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AddlImm::AddlImm(ExtMachInst machInst)
         : IntegerImm("addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::addlv(['\n                int32_t tmp  = Ra_sl + Rb_or_imm_sl;\n                // signed overflow occurs when operands have same sign\n                // and sign of result does not match.\n                if (Ra_sl<31:> == Rb_or_imm_sl<31:> && tmp<31:> != Ra_sl<31:>)\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp;\n            '],{})

    Addlv::Addlv(ExtMachInst machInst)
         : AlphaStaticInst("addlv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AddlvImm::AddlvImm(ExtMachInst machInst)
         : IntegerImm("addlv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s4addl([' Rc_sl = (Ra_sl << 2) + Rb_or_imm_sl; '],{})

    S4addl::S4addl(ExtMachInst machInst)
         : AlphaStaticInst("s4addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S4addlImm::S4addlImm(ExtMachInst machInst)
         : IntegerImm("s4addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s8addl([' Rc_sl = (Ra_sl << 3) + Rb_or_imm_sl; '],{})

    S8addl::S8addl(ExtMachInst machInst)
         : AlphaStaticInst("s8addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S8addlImm::S8addlImm(ExtMachInst machInst)
         : IntegerImm("s8addl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::addq([' Rc = Ra + Rb_or_imm; '],{})

    Addq::Addq(ExtMachInst machInst)
         : AlphaStaticInst("addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AddqImm::AddqImm(ExtMachInst machInst)
         : IntegerImm("addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::addqv(['\n                uint64_t tmp = Ra + Rb_or_imm;\n                // signed overflow occurs when operands have same sign\n                // and sign of result does not match.\n                if (Ra<63:> == Rb_or_imm<63:> && tmp<63:> != Ra<63:>)\n                    fault = new IntegerOverflowFault;\n                Rc = tmp;\n            '],{})

    Addqv::Addqv(ExtMachInst machInst)
         : AlphaStaticInst("addqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AddqvImm::AddqvImm(ExtMachInst machInst)
         : IntegerImm("addqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s4addq([' Rc = (Ra << 2) + Rb_or_imm; '],{})

    S4addq::S4addq(ExtMachInst machInst)
         : AlphaStaticInst("s4addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S4addqImm::S4addqImm(ExtMachInst machInst)
         : IntegerImm("s4addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s8addq([' Rc = (Ra << 3) + Rb_or_imm; '],{})

    S8addq::S8addq(ExtMachInst machInst)
         : AlphaStaticInst("s8addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S8addqImm::S8addqImm(ExtMachInst machInst)
         : IntegerImm("s8addq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::subl([' Rc_sl = Ra_sl - Rb_or_imm_sl; '],{})

    Subl::Subl(ExtMachInst machInst)
         : AlphaStaticInst("subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SublImm::SublImm(ExtMachInst machInst)
         : IntegerImm("subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::sublv(['\n                int32_t tmp  = Ra_sl - Rb_or_imm_sl;\n                // signed overflow detection is same as for add,\n                // except we need to look at the *complemented*\n                // sign bit of the subtrahend (Rb), i.e., if the initial\n                // signs are the *same* then no overflow can occur\n                if (Ra_sl<31:> != Rb_or_imm_sl<31:> && tmp<31:> != Ra_sl<31:>)\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp;\n            '],{})

    Sublv::Sublv(ExtMachInst machInst)
         : AlphaStaticInst("sublv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SublvImm::SublvImm(ExtMachInst machInst)
         : IntegerImm("sublv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s4subl([' Rc_sl = (Ra_sl << 2) - Rb_or_imm_sl; '],{})

    S4subl::S4subl(ExtMachInst machInst)
         : AlphaStaticInst("s4subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S4sublImm::S4sublImm(ExtMachInst machInst)
         : IntegerImm("s4subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s8subl([' Rc_sl = (Ra_sl << 3) - Rb_or_imm_sl; '],{})

    S8subl::S8subl(ExtMachInst machInst)
         : AlphaStaticInst("s8subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S8sublImm::S8sublImm(ExtMachInst machInst)
         : IntegerImm("s8subl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::subq([' Rc = Ra - Rb_or_imm; '],{})

    Subq::Subq(ExtMachInst machInst)
         : AlphaStaticInst("subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SubqImm::SubqImm(ExtMachInst machInst)
         : IntegerImm("subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::subqv(['\n                uint64_t tmp  = Ra - Rb_or_imm;\n                // signed overflow detection is same as for add,\n                // except we need to look at the *complemented*\n                // sign bit of the subtrahend (Rb), i.e., if the initial\n                // signs are the *same* then no overflow can occur\n                if (Ra<63:> != Rb_or_imm<63:> && tmp<63:> != Ra<63:>)\n                    fault = new IntegerOverflowFault;\n                Rc = tmp;\n            '],{})

    Subqv::Subqv(ExtMachInst machInst)
         : AlphaStaticInst("subqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SubqvImm::SubqvImm(ExtMachInst machInst)
         : IntegerImm("subqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s4subq([' Rc = (Ra << 2) - Rb_or_imm; '],{})

    S4subq::S4subq(ExtMachInst machInst)
         : AlphaStaticInst("s4subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S4subqImm::S4subqImm(ExtMachInst machInst)
         : IntegerImm("s4subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::s8subq([' Rc = (Ra << 3) - Rb_or_imm; '],{})

    S8subq::S8subq(ExtMachInst machInst)
         : AlphaStaticInst("s8subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    S8subqImm::S8subqImm(ExtMachInst machInst)
         : IntegerImm("s8subq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmpeq([' Rc = (Ra == Rb_or_imm); '],{})

    Cmpeq::Cmpeq(ExtMachInst machInst)
         : AlphaStaticInst("cmpeq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpeqImm::CmpeqImm(ExtMachInst machInst)
         : IntegerImm("cmpeq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmple([' Rc = (Ra_sq <= Rb_or_imm_sq); '],{})

    Cmple::Cmple(ExtMachInst machInst)
         : AlphaStaticInst("cmple", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpleImm::CmpleImm(ExtMachInst machInst)
         : IntegerImm("cmple", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmplt([' Rc = (Ra_sq <  Rb_or_imm_sq); '],{})

    Cmplt::Cmplt(ExtMachInst machInst)
         : AlphaStaticInst("cmplt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpltImm::CmpltImm(ExtMachInst machInst)
         : IntegerImm("cmplt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmpule([' Rc = (Ra_uq <= Rb_or_imm_uq); '],{})

    Cmpule::Cmpule(ExtMachInst machInst)
         : AlphaStaticInst("cmpule", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpuleImm::CmpuleImm(ExtMachInst machInst)
         : IntegerImm("cmpule", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmpult([' Rc = (Ra_uq <  Rb_or_imm_uq); '],{})

    Cmpult::Cmpult(ExtMachInst machInst)
         : AlphaStaticInst("cmpult", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpultImm::CmpultImm(ExtMachInst machInst)
         : IntegerImm("cmpult", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmpbge(['\n                int hi = 7;\n                int lo = 0;\n                uint64_t tmp = 0;\n                for (int i = 0; i < 8; ++i) {\n                    tmp |= (Ra_uq<hi:lo> >= Rb_or_imm_uq<hi:lo>) << i;\n                    hi += 8;\n                    lo += 8;\n                }\n                Rc = tmp;\n            '],{})

    Cmpbge::Cmpbge(ExtMachInst machInst)
         : AlphaStaticInst("cmpbge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmpbgeImm::CmpbgeImm(ExtMachInst machInst)
         : IntegerImm("cmpbge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::and([' Rc = Ra & Rb_or_imm; '],{})

    And::And(ExtMachInst machInst)
         : AlphaStaticInst("and", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AndImm::AndImm(ExtMachInst machInst)
         : IntegerImm("and", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::bic([' Rc = Ra & ~Rb_or_imm; '],{})

    Bic::Bic(ExtMachInst machInst)
         : AlphaStaticInst("bic", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    BicImm::BicImm(ExtMachInst machInst)
         : IntegerImm("bic", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::bis([' Rc = Ra | Rb_or_imm; '],{})

    Bis::Bis(ExtMachInst machInst)
         : AlphaStaticInst("bis", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    BisImm::BisImm(ExtMachInst machInst)
         : IntegerImm("bis", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::ornot([' Rc = Ra | ~Rb_or_imm; '],{})

    Ornot::Ornot(ExtMachInst machInst)
         : AlphaStaticInst("ornot", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    OrnotImm::OrnotImm(ExtMachInst machInst)
         : IntegerImm("ornot", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::xor([' Rc = Ra ^ Rb_or_imm; '],{})

    Xor::Xor(ExtMachInst machInst)
         : AlphaStaticInst("xor", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    XorImm::XorImm(ExtMachInst machInst)
         : IntegerImm("xor", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::eqv([' Rc = Ra ^ ~Rb_or_imm; '],{})

    Eqv::Eqv(ExtMachInst machInst)
         : AlphaStaticInst("eqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    EqvImm::EqvImm(ExtMachInst machInst)
         : IntegerImm("eqv", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovlbs([' Rc = ((Ra & 1) == 1) ? Rb_or_imm : Rc; '],{})

    Cmovlbs::Cmovlbs(ExtMachInst machInst)
         : AlphaStaticInst("cmovlbs", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovlbsImm::CmovlbsImm(ExtMachInst machInst)
         : IntegerImm("cmovlbs", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovlbc([' Rc = ((Ra & 1) == 0) ? Rb_or_imm : Rc; '],{})

    Cmovlbc::Cmovlbc(ExtMachInst machInst)
         : AlphaStaticInst("cmovlbc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovlbcImm::CmovlbcImm(ExtMachInst machInst)
         : IntegerImm("cmovlbc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmoveq([' Rc = (Ra == 0) ? Rb_or_imm : Rc; '],{})

    Cmoveq::Cmoveq(ExtMachInst machInst)
         : AlphaStaticInst("cmoveq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmoveqImm::CmoveqImm(ExtMachInst machInst)
         : IntegerImm("cmoveq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovne([' Rc = (Ra != 0) ? Rb_or_imm : Rc; '],{})

    Cmovne::Cmovne(ExtMachInst machInst)
         : AlphaStaticInst("cmovne", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovneImm::CmovneImm(ExtMachInst machInst)
         : IntegerImm("cmovne", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovlt([' Rc = (Ra_sq <  0) ? Rb_or_imm : Rc; '],{})

    Cmovlt::Cmovlt(ExtMachInst machInst)
         : AlphaStaticInst("cmovlt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovltImm::CmovltImm(ExtMachInst machInst)
         : IntegerImm("cmovlt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovge([' Rc = (Ra_sq >= 0) ? Rb_or_imm : Rc; '],{})

    Cmovge::Cmovge(ExtMachInst machInst)
         : AlphaStaticInst("cmovge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovgeImm::CmovgeImm(ExtMachInst machInst)
         : IntegerImm("cmovge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovle([' Rc = (Ra_sq <= 0) ? Rb_or_imm : Rc; '],{})

    Cmovle::Cmovle(ExtMachInst machInst)
         : AlphaStaticInst("cmovle", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovleImm::CmovleImm(ExtMachInst machInst)
         : IntegerImm("cmovle", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cmovgt([' Rc = (Ra_sq >  0) ? Rb_or_imm : Rc; '],{})

    Cmovgt::Cmovgt(ExtMachInst machInst)
         : AlphaStaticInst("cmovgt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    CmovgtImm::CmovgtImm(ExtMachInst machInst)
         : IntegerImm("cmovgt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RC] : RC;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::amask([' Rc = Rb_or_imm & ~ULL(0x17); '],{})

    Amask::Amask(ExtMachInst machInst)
         : AlphaStaticInst("amask", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    AmaskImm::AmaskImm(ExtMachInst machInst)
         : IntegerImm("amask", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::implver([' Rc = FullSystem ? 1 : 2 '],{})

    Implver::Implver(ExtMachInst machInst)
         : AlphaStaticInst("implver", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// WarnUnimpl::eleven25(([], {}))

// Unknown::unknown(([], {}))

// IntegerOperate::sll([' Rc = Ra << Rb_or_imm<5:0>; '],{})

    Sll::Sll(ExtMachInst machInst)
         : AlphaStaticInst("sll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SllImm::SllImm(ExtMachInst machInst)
         : IntegerImm("sll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::srl([' Rc = Ra_uq >> Rb_or_imm<5:0>; '],{})

    Srl::Srl(ExtMachInst machInst)
         : AlphaStaticInst("srl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SrlImm::SrlImm(ExtMachInst machInst)
         : IntegerImm("srl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::sra([' Rc = Ra_sq >> Rb_or_imm<5:0>; '],{})

    Sra::Sra(ExtMachInst machInst)
         : AlphaStaticInst("sra", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SraImm::SraImm(ExtMachInst machInst)
         : IntegerImm("sra", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskbl([' Rc = Ra & ~(mask( 8) << (Rb_or_imm<2:0> * 8)); '],{})

    Mskbl::Mskbl(ExtMachInst machInst)
         : AlphaStaticInst("mskbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskblImm::MskblImm(ExtMachInst machInst)
         : IntegerImm("mskbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskwl([' Rc = Ra & ~(mask(16) << (Rb_or_imm<2:0> * 8)); '],{})

    Mskwl::Mskwl(ExtMachInst machInst)
         : AlphaStaticInst("mskwl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskwlImm::MskwlImm(ExtMachInst machInst)
         : IntegerImm("mskwl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskll([' Rc = Ra & ~(mask(32) << (Rb_or_imm<2:0> * 8)); '],{})

    Mskll::Mskll(ExtMachInst machInst)
         : AlphaStaticInst("mskll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskllImm::MskllImm(ExtMachInst machInst)
         : IntegerImm("mskll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskql([' Rc = Ra & ~(mask(64) << (Rb_or_imm<2:0> * 8)); '],{})

    Mskql::Mskql(ExtMachInst machInst)
         : AlphaStaticInst("mskql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskqlImm::MskqlImm(ExtMachInst machInst)
         : IntegerImm("mskql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskwh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(16) >> (64 - 8 * bv))) : Ra;\n            '],{})

    Mskwh::Mskwh(ExtMachInst machInst)
         : AlphaStaticInst("mskwh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskwhImm::MskwhImm(ExtMachInst machInst)
         : IntegerImm("mskwh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::msklh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(32) >> (64 - 8 * bv))) : Ra;\n            '],{})

    Msklh::Msklh(ExtMachInst machInst)
         : AlphaStaticInst("msklh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MsklhImm::MsklhImm(ExtMachInst machInst)
         : IntegerImm("msklh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mskqh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc =  bv ? (Ra & ~(mask(64) >> (64 - 8 * bv))) : Ra;\n            '],{})

    Mskqh::Mskqh(ExtMachInst machInst)
         : AlphaStaticInst("mskqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MskqhImm::MskqhImm(ExtMachInst machInst)
         : IntegerImm("mskqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extbl([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))< 7:0>; '],{})

    Extbl::Extbl(ExtMachInst machInst)
         : AlphaStaticInst("extbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtblImm::ExtblImm(ExtMachInst machInst)
         : IntegerImm("extbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extwl([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))<15:0>; '],{})

    Extwl::Extwl(ExtMachInst machInst)
         : AlphaStaticInst("extwl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtwlImm::ExtwlImm(ExtMachInst machInst)
         : IntegerImm("extwl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extll([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8))<31:0>; '],{})

    Extll::Extll(ExtMachInst machInst)
         : AlphaStaticInst("extll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtllImm::ExtllImm(ExtMachInst machInst)
         : IntegerImm("extll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extql([' Rc = (Ra_uq >> (Rb_or_imm<2:0> * 8)); '],{})

    Extql::Extql(ExtMachInst machInst)
         : AlphaStaticInst("extql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtqlImm::ExtqlImm(ExtMachInst machInst)
         : IntegerImm("extql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extwh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>)<15:0>; '],{})

    Extwh::Extwh(ExtMachInst machInst)
         : AlphaStaticInst("extwh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtwhImm::ExtwhImm(ExtMachInst machInst)
         : IntegerImm("extwh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extlh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>)<31:0>; '],{})

    Extlh::Extlh(ExtMachInst machInst)
         : AlphaStaticInst("extlh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtlhImm::ExtlhImm(ExtMachInst machInst)
         : IntegerImm("extlh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::extqh(['\n                Rc = (Ra << (64 - (Rb_or_imm<2:0> * 8))<5:0>); '],{})

    Extqh::Extqh(ExtMachInst machInst)
         : AlphaStaticInst("extqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ExtqhImm::ExtqhImm(ExtMachInst machInst)
         : IntegerImm("extqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::insbl([' Rc = Ra< 7:0> << (Rb_or_imm<2:0> * 8); '],{})

    Insbl::Insbl(ExtMachInst machInst)
         : AlphaStaticInst("insbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InsblImm::InsblImm(ExtMachInst machInst)
         : IntegerImm("insbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::inswl([' Rc = Ra<15:0> << (Rb_or_imm<2:0> * 8); '],{})

    Inswl::Inswl(ExtMachInst machInst)
         : AlphaStaticInst("inswl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InswlImm::InswlImm(ExtMachInst machInst)
         : IntegerImm("inswl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::insll([' Rc = Ra<31:0> << (Rb_or_imm<2:0> * 8); '],{})

    Insll::Insll(ExtMachInst machInst)
         : AlphaStaticInst("insll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InsllImm::InsllImm(ExtMachInst machInst)
         : IntegerImm("insll", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::insql([' Rc = Ra       << (Rb_or_imm<2:0> * 8); '],{})

    Insql::Insql(ExtMachInst machInst)
         : AlphaStaticInst("insql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InsqlImm::InsqlImm(ExtMachInst machInst)
         : IntegerImm("insql", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::inswh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq<15:0> >> (64 - 8 * bv)) : 0;\n            '],{})

    Inswh::Inswh(ExtMachInst machInst)
         : AlphaStaticInst("inswh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InswhImm::InswhImm(ExtMachInst machInst)
         : IntegerImm("inswh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::inslh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq<31:0> >> (64 - 8 * bv)) : 0;\n            '],{})

    Inslh::Inslh(ExtMachInst machInst)
         : AlphaStaticInst("inslh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InslhImm::InslhImm(ExtMachInst machInst)
         : IntegerImm("inslh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::insqh(['\n                int bv = Rb_or_imm<2:0>;\n                Rc = bv ? (Ra_uq       >> (64 - 8 * bv)) : 0;\n            '],{})

    Insqh::Insqh(ExtMachInst machInst)
         : AlphaStaticInst("insqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    InsqhImm::InsqhImm(ExtMachInst machInst)
         : IntegerImm("insqh", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::zap(['\n                uint64_t zapmask = 0;\n                for (int i = 0; i < 8; ++i) {\n                    if (Rb_or_imm<i:>)\n                        zapmask |= (mask(8) << (i * 8));\n                }\n                Rc = Ra & ~zapmask;\n            '],{})

    Zap::Zap(ExtMachInst machInst)
         : AlphaStaticInst("zap", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ZapImm::ZapImm(ExtMachInst machInst)
         : IntegerImm("zap", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::zapnot(['\n                uint64_t zapmask = 0;\n                for (int i = 0; i < 8; ++i) {\n                    if (!Rb_or_imm<i:>)\n                        zapmask |= (mask(8) << (i * 8));\n                }\n                Rc = Ra & ~zapmask;\n            '],{})

    Zapnot::Zapnot(ExtMachInst machInst)
         : AlphaStaticInst("zapnot", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    ZapnotImm::ZapnotImm(ExtMachInst machInst)
         : IntegerImm("zapnot", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::mull([' Rc_sl = Ra_sl * Rb_or_imm_sl; ', 'IntMultOp'],{})

    Mull::Mull(ExtMachInst machInst)
         : AlphaStaticInst("mull", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MullImm::MullImm(ExtMachInst machInst)
         : IntegerImm("mull", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mulq([' Rc    = Ra    * Rb_or_imm;    ', 'IntMultOp'],{})

    Mulq::Mulq(ExtMachInst machInst)
         : AlphaStaticInst("mulq", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MulqImm::MulqImm(ExtMachInst machInst)
         : IntegerImm("mulq", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::umulh(['\n                uint64_t hi, lo;\n                mul128(Ra, Rb_or_imm, hi, lo);\n                Rc = hi;\n            ', 'IntMultOp'],{})

    Umulh::Umulh(ExtMachInst machInst)
         : AlphaStaticInst("umulh", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    UmulhImm::UmulhImm(ExtMachInst machInst)
         : IntegerImm("umulh", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mullv(['\n                // 32-bit multiply with trap on overflow\n                int64_t Rax = Ra_sl;    // sign extended version of Ra_sl\n                int64_t Rbx = Rb_or_imm_sl;\n                int64_t tmp = Rax * Rbx;\n                // To avoid overflow, all the upper 32 bits must match\n                // the sign bit of the lower 32.  We code this as\n                // checking the upper 33 bits for all 0s or all 1s.\n                uint64_t sign_bits = tmp<63:31>;\n                if (sign_bits != 0 && sign_bits != mask(33))\n                    fault = new IntegerOverflowFault;\n                Rc_sl = tmp<31:0>;\n            ', 'IntMultOp'],{})

    Mullv::Mullv(ExtMachInst machInst)
         : AlphaStaticInst("mullv", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MullvImm::MullvImm(ExtMachInst machInst)
         : IntegerImm("mullv", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::mulqv(['\n                // 64-bit multiply with trap on overflow\n                uint64_t hi, lo;\n                mul128(Ra, Rb_or_imm, hi, lo);\n                // all the upper 64 bits must match the sign bit of\n                // the lower 64\n                if (!((hi == 0 && lo<63:> == 0) ||\n                      (hi == mask(64) && lo<63:> == 1)))\n                    fault = new IntegerOverflowFault;\n                Rc = lo;\n            ', 'IntMultOp'],{})

    Mulqv::Mulqv(ExtMachInst machInst)
         : AlphaStaticInst("mulqv", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    MulqvImm::MulqvImm(ExtMachInst machInst)
         : IntegerImm("mulqv", machInst, IntMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::sextb([' Rc_sb = Rb_or_imm< 7:0>; '],{})

    Sextb::Sextb(ExtMachInst machInst)
         : AlphaStaticInst("sextb", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SextbImm::SextbImm(ExtMachInst machInst)
         : IntegerImm("sextb", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::sextw([' Rc_sw = Rb_or_imm<15:0>; '],{})

    Sextw::Sextw(ExtMachInst machInst)
         : AlphaStaticInst("sextw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

    SextwImm::SextwImm(ExtMachInst machInst)
         : IntegerImm("sextw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// IntegerOperate::ctpop(['\n                             uint64_t count = 0;\n                             for (int i = 0; Rb<63:i>; ++i) {\n                                 if (Rb<i:i> == 0x1)\n                                     ++count;\n                             }\n                             Rc = count;\n                           ', 'IntAluOp'],{})

    Ctpop::Ctpop(ExtMachInst machInst)
         : AlphaStaticInst("ctpop", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::perr(['\n                             uint64_t temp = 0;\n                             int hi = 7;\n                             int lo = 0;\n                             for (int i = 0; i < 8; ++i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp += (ra_ub >= rb_ub) ? \n                                         (ra_ub - rb_ub) : (rb_ub - ra_ub);\n                                 hi += 8;\n                                 lo += 8;\n                             }\n                             Rc = temp;\n                           '],{})

    Perr::Perr(ExtMachInst machInst)
         : AlphaStaticInst("perr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::ctlz(['\n                             uint64_t count = 0;\n                             uint64_t temp = Rb;\n                             if (temp<63:32>) temp >>= 32; else count += 32;\n                             if (temp<31:16>) temp >>= 16; else count += 16;\n                             if (temp<15:8>) temp >>= 8; else count += 8;\n                             if (temp<7:4>) temp >>= 4; else count += 4;\n                             if (temp<3:2>) temp >>= 2; else count += 2;\n                             if (temp<1:1>) temp >>= 1; else count += 1;\n                             if ((temp<0:0>) != 0x1) count += 1;\n                             Rc = count;\n                           ', 'IntAluOp'],{})

    Ctlz::Ctlz(ExtMachInst machInst)
         : AlphaStaticInst("ctlz", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::cttz(['\n                             uint64_t count = 0;\n                             uint64_t temp = Rb;\n                             if (!(temp<31:0>)) { temp >>= 32; count += 32; }\n                             if (!(temp<15:0>)) { temp >>= 16; count += 16; }\n                             if (!(temp<7:0>)) { temp >>= 8; count += 8; }\n                             if (!(temp<3:0>)) { temp >>= 4; count += 4; }\n                             if (!(temp<1:0>)) { temp >>= 2; count += 2; }\n                             if (!(temp<0:0> & ULL(0x1))) { \n                                 temp >>= 1; count += 1; \n                             }\n                             if (!(temp<0:0> & ULL(0x1))) count += 1;\n                             Rc = count;\n                           ', 'IntAluOp'],{})

    Cttz::Cttz(ExtMachInst machInst)
         : AlphaStaticInst("cttz", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::unpkbw([' \n                             Rc = (Rb_uq<7:0>\n                                   | (Rb_uq<15:8> << 16)\n                                   | (Rb_uq<23:16> << 32)\n                                   | (Rb_uq<31:24> << 48));\n                           ', 'IntAluOp'],{})

    Unpkbw::Unpkbw(ExtMachInst machInst)
         : AlphaStaticInst("unpkbw", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::unpkbl(['\n                             Rc = (Rb_uq<7:0> | (Rb_uq<15:8> << 32));\n                           ', 'IntAluOp'],{})

    Unpkbl::Unpkbl(ExtMachInst machInst)
         : AlphaStaticInst("unpkbl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::pkwb(['\n                             Rc = (Rb_uq<7:0>\n                                   | (Rb_uq<23:16> << 8)\n                                   | (Rb_uq<39:32> << 16)\n                                   | (Rb_uq<55:48> << 24));\n                           ', 'IntAluOp'],{})

    Pkwb::Pkwb(ExtMachInst machInst)
         : AlphaStaticInst("pkwb", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::pklb(['\n                             Rc = (Rb_uq<7:0> | (Rb_uq<39:32> << 8));\n                           ', 'IntAluOp'],{})

    Pklb::Pklb(ExtMachInst machInst)
         : AlphaStaticInst("pklb", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::minsb8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 int8_t ra_sb = Ra_uq<hi:lo>;\n                                 int8_t rb_sb = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_sb < rb_sb) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})

    Minsb8::Minsb8(ExtMachInst machInst)
         : AlphaStaticInst("minsb8", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::minsw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 int16_t ra_sw = Ra_uq<hi:lo>;\n                                 int16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw < rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})

    Minsw4::Minsw4(ExtMachInst machInst)
         : AlphaStaticInst("minsw4", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::minub8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_ub < rb_ub) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})

    Minub8::Minub8(ExtMachInst machInst)
         : AlphaStaticInst("minub8", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::minuw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 uint16_t ra_sw = Ra_uq<hi:lo>;\n                                 uint16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw < rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})

    Minuw4::Minuw4(ExtMachInst machInst)
         : AlphaStaticInst("minuw4", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::maxub8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 uint8_t ra_ub = Ra_uq<hi:lo>;\n                                 uint8_t rb_ub = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_ub > rb_ub) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})

    Maxub8::Maxub8(ExtMachInst machInst)
         : AlphaStaticInst("maxub8", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::maxuw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 uint16_t ra_uw = Ra_uq<hi:lo>;\n                                 uint16_t rb_uw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_uw > rb_uw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})

    Maxuw4::Maxuw4(ExtMachInst machInst)
         : AlphaStaticInst("maxuw4", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::maxsb8(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 56;\n                             for (int i = 7; i >= 0; --i) {\n                                 int8_t ra_sb = Ra_uq<hi:lo>;\n                                 int8_t rb_sb = Rb_uq<hi:lo>;\n                                 temp = ((temp << 8) \n                                         | ((ra_sb > rb_sb) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 8;\n                                 lo -= 8;\n                             }\n                             Rc = temp;\n                          '],{})

    Maxsb8::Maxsb8(ExtMachInst machInst)
         : AlphaStaticInst("maxsb8", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// IntegerOperate::maxsw4(['\n                             uint64_t temp = 0;\n                             int hi = 63;\n                             int lo = 48;\n                             for (int i = 3; i >= 0; --i) {\n                                 int16_t ra_sw = Ra_uq<hi:lo>;\n                                 int16_t rb_sw = Rb_uq<hi:lo>;\n                                 temp = ((temp << 16) \n                                         | ((ra_sw > rb_sw) ? Ra_uq<hi:lo>\n                                                          : Rb_uq<hi:lo>));\n                                 hi -= 16;\n                                 lo -= 16;\n                             }\n                             Rc = temp;\n                          '],{})

    Maxsw4::Maxsw4(ExtMachInst machInst)
         : AlphaStaticInst("maxsw4", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// BasicOperateWithNopCheck::ftoit([' Rc = Fa_uq; ', 'FloatCvtOp'],{})

    Ftoit::Ftoit(ExtMachInst machInst)
         : AlphaStaticInst("ftoit", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// BasicOperateWithNopCheck::ftois([' Rc_sl = t_to_s(Fa_uq); ', 'FloatCvtOp'],{})

    Ftois::Ftois(ExtMachInst machInst)
         : AlphaStaticInst("ftois", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RC] : RC;
	_numIntDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// CondBranch::beq([' cond = (Ra == 0); '],{})

    Beq::Beq(ExtMachInst machInst)
         : Branch("beq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::bne([' cond = (Ra != 0); '],{})

    Bne::Bne(ExtMachInst machInst)
         : Branch("bne", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::bge([' cond = (Ra_sq >= 0); '],{})

    Bge::Bge(ExtMachInst machInst)
         : Branch("bge", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::bgt([' cond = (Ra_sq >  0); '],{})

    Bgt::Bgt(ExtMachInst machInst)
         : Branch("bgt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::ble([' cond = (Ra_sq <= 0); '],{})

    Ble::Ble(ExtMachInst machInst)
         : Branch("ble", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::blt([' cond = (Ra_sq < 0); '],{})

    Blt::Blt(ExtMachInst machInst)
         : Branch("blt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::blbc([' cond = ((Ra & 1) == 0); '],{})

    Blbc::Blbc(ExtMachInst machInst)
         : Branch("blbc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::blbs([' cond = ((Ra & 1) == 1); '],{})

    Blbs::Blbs(ExtMachInst machInst)
         : Branch("blbs", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
    }

// CondBranch::fbeq([' cond = (Fa == 0); '],{})

    Fbeq::Fbeq(ExtMachInst machInst)
         : Branch("fbeq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// CondBranch::fbne([' cond = (Fa != 0); '],{})

    Fbne::Fbne(ExtMachInst machInst)
         : Branch("fbne", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// CondBranch::fbge([' cond = (Fa >= 0); '],{})

    Fbge::Fbge(ExtMachInst machInst)
         : Branch("fbge", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// CondBranch::fbgt([' cond = (Fa >  0); '],{})

    Fbgt::Fbgt(ExtMachInst machInst)
         : Branch("fbgt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// CondBranch::fble([' cond = (Fa <= 0); '],{})

    Fble::Fble(ExtMachInst machInst)
         : Branch("fble", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// CondBranch::fblt([' cond = (Fa < 0); '],{})

    Fblt::Fblt(ExtMachInst machInst)
         : Branch("fblt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsFloating] = true;;
    }

// UncondBranch::br([],{})

    Br::Br(ExtMachInst machInst)
         : Branch("br", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsUncondControl] = true;;
    }

    BrAndLink::BrAndLink(ExtMachInst machInst)
         : Branch("br", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

// UncondBranch::bsr(['IsCall'],{})

    Bsr::Bsr(ExtMachInst machInst)
         : Branch("bsr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsUncondControl] = true;;
    }

    BsrAndLink::BsrAndLink(ExtMachInst machInst)
         : Branch("bsr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

// Jump::jmp([],{})

    Jmp::Jmp(ExtMachInst machInst)
         : Jump("jmp", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

    JmpAndLink::JmpAndLink(ExtMachInst machInst)
         : Jump("jmp", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

// Jump::jsr(['IsCall'],{})

    Jsr::Jsr(ExtMachInst machInst)
         : Jump("jsr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

    JsrAndLink::JsrAndLink(ExtMachInst machInst)
         : Jump("jsr", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
    }

// Jump::ret(['IsReturn'],{})

    Ret::Ret(ExtMachInst machInst)
         : Jump("ret", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsReturn] = true;
	flags[IsUncondControl] = true;;
    }

    RetAndLink::RetAndLink(ExtMachInst machInst)
         : Jump("ret", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsReturn] = true;
	flags[IsUncondControl] = true;;
    }

// Jump::jsr_coroutine(['IsCall', 'IsReturn'],{})

    Jsr_coroutine::Jsr_coroutine(ExtMachInst machInst)
         : Jump("jsr_coroutine", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsReturn] = true;
	flags[IsUncondControl] = true;;
    }

    Jsr_coroutineAndLink::Jsr_coroutineAndLink(ExtMachInst machInst)
         : Jump("jsr_coroutine", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsReturn] = true;
	flags[IsUncondControl] = true;;
    }

// Unknown::unknown(([], {}))

// BasicOperateWithNopCheck::itofs([' Fc_uq = s_to_t(Ra_ul); ', 'FloatCvtOp'],{})

    Itofs::Itofs(ExtMachInst machInst)
         : AlphaStaticInst("itofs", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// BasicOperateWithNopCheck::itoft([' Fc_uq = Ra_uq; ', 'FloatCvtOp'],{})

    Itoft::Itoft(ExtMachInst machInst)
         : AlphaStaticInst("itoft", machInst, FloatCvtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FailUnimpl::itoff(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))
#if SS_COMPATIBLE_FP

// FloatingPointOperate::sqrts(['\n                        if (Fb < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc = sqrt(Fb);\n                    ', 'FloatSqrtOp'],{})

    Sqrts::Sqrts(ExtMachInst machInst)
         : AlphaFP("sqrts", machInst, FloatSqrtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }
#else

// FloatingPointOperate::sqrts(['\n                        if (Fb_sf < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc_sf = sqrt(Fb_sf);\n                    ', 'FloatSqrtOp'],{})

    Sqrts::Sqrts(ExtMachInst machInst)
         : AlphaFP("sqrts", machInst, FloatSqrtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }
#endif

// FloatingPointOperate::sqrtt(['\n                        if (Fb < 0.0)\n                            fault = new ArithmeticFault;\n                        Fc = sqrt(Fb);\n                    ', 'FloatSqrtOp'],{})

    Sqrtt::Sqrtt(ExtMachInst machInst)
         : AlphaFP("sqrtt", machInst, FloatSqrtOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// FailUnimpl::sqrtfg(([], {}))

// Unknown::unknown(([], {}))
#if SS_COMPATIBLE_FP

// FloatingPointOperate::adds([' Fc = Fa + Fb; '],{})

    Adds::Adds(ExtMachInst machInst)
         : AlphaFP("adds", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::subs([' Fc = Fa - Fb; '],{})

    Subs::Subs(ExtMachInst machInst)
         : AlphaFP("subs", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::muls([' Fc = Fa * Fb; ', 'FloatMultOp'],{})

    Muls::Muls(ExtMachInst machInst)
         : AlphaFP("muls", machInst, FloatMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::divs([' Fc = Fa / Fb; ', 'FloatDivOp'],{})

    Divs::Divs(ExtMachInst machInst)
         : AlphaFP("divs", machInst, FloatDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }
#else

// FloatingPointOperate::adds([' Fc_sf = Fa_sf + Fb_sf; '],{})

    Adds::Adds(ExtMachInst machInst)
         : AlphaFP("adds", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::subs([' Fc_sf = Fa_sf - Fb_sf; '],{})

    Subs::Subs(ExtMachInst machInst)
         : AlphaFP("subs", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::muls([' Fc_sf = Fa_sf * Fb_sf; ', 'FloatMultOp'],{})

    Muls::Muls(ExtMachInst machInst)
         : AlphaFP("muls", machInst, FloatMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::divs([' Fc_sf = Fa_sf / Fb_sf; ', 'FloatDivOp'],{})

    Divs::Divs(ExtMachInst machInst)
         : AlphaFP("divs", machInst, FloatDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }
#endif

// FloatingPointOperate::addt([' Fc = Fa + Fb; '],{})

    Addt::Addt(ExtMachInst machInst)
         : AlphaFP("addt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::subt([' Fc = Fa - Fb; '],{})

    Subt::Subt(ExtMachInst machInst)
         : AlphaFP("subt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::mult([' Fc = Fa * Fb; ', 'FloatMultOp'],{})

    Mult::Mult(ExtMachInst machInst)
         : AlphaFP("mult", machInst, FloatMultOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::divt([' Fc = Fa / Fb; ', 'FloatDivOp'],{})

    Divt::Divt(ExtMachInst machInst)
         : AlphaFP("divt", machInst, FloatDivOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// BasicOperateWithNopCheck::cmpteq([' Fc = (Fa == Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})

    Cmpteq::Cmpteq(ExtMachInst machInst)
         : AlphaStaticInst("cmpteq", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cmptle([' Fc = (Fa <= Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})

    Cmptle::Cmptle(ExtMachInst machInst)
         : AlphaStaticInst("cmptle", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cmptlt([' Fc = (Fa <  Fb) ? 2.0 : 0.0; ', 'FloatCmpOp'],{})

    Cmptlt::Cmptlt(ExtMachInst machInst)
         : AlphaStaticInst("cmptlt", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cmptun([' // unordered\n                    Fc = (!(Fa < Fb) && !(Fa == Fb) && !(Fa > Fb)) ? 2.0 : 0.0;\n                ', 'FloatCmpOp'],{})

    Cmptun::Cmptun(ExtMachInst machInst)
         : AlphaStaticInst("cmptun", machInst, FloatCmpOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPFixedRounding::cvttq([' Fc_sq = (int64_t)trunc(Fb); ', 'Chopped'],{})

    CvttqChopped::CvttqChopped(ExtMachInst machInst)
         : AlphaFP("cvttq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FPFixedRounding::cvttq([' Fc_sq = (int64_t)floor(Fb); ', 'MinusInfinity'],{})

    CvttqMinusInfinity::CvttqMinusInfinity(ExtMachInst machInst)
         : AlphaFP("cvttq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::cvttq([' Fc_sq = (int64_t)nearbyint(Fb); '],{})

    Cvttq::Cvttq(ExtMachInst machInst)
         : AlphaFP("cvttq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cvtst([' Fc = Fb_sf; '],{})

    Cvtst::Cvtst(ExtMachInst machInst)
         : AlphaStaticInst("cvtst", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::cvtts([' Fc_sf = Fb; '],{})

    Cvtts::Cvtts(ExtMachInst machInst)
         : AlphaFP("cvtts", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// FloatingPointOperate::cvtqs([' Fc_sf = Fb_sq; '],{})

    Cvtqs::Cvtqs(ExtMachInst machInst)
         : AlphaFP("cvtqs", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FloatingPointOperate::cvtqt([' Fc    = Fb_sq; '],{})

    Cvtqt::Cvtqt(ExtMachInst machInst)
         : AlphaFP("cvtqt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// BasicOperateWithNopCheck::cvtlq(['\n                Fc_sl = (Fb_uq<63:62> << 30) | Fb_uq<58:29>;\n            '],{})

    Cvtlq::Cvtlq(ExtMachInst machInst)
         : AlphaStaticInst("cvtlq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cvtql(['\n                Fc_uq = (Fb_uq<31:30> << 62) | (Fb_uq<29:0> << 29);\n            '],{})

    Cvtql::Cvtql(ExtMachInst machInst)
         : AlphaStaticInst("cvtql", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cvtqlv(['\n                // To avoid overflow, all the upper 32 bits must match\n                // the sign bit of the lower 32.  We code this as\n                // checking the upper 33 bits for all 0s or all 1s.\n                uint64_t sign_bits = Fb_uq<63:31>;\n                if (sign_bits != 0 && sign_bits != mask(33))\n                    fault = new IntegerOverflowFault;\n                Fc_uq = (Fb_uq<31:30> << 62) | (Fb_uq<29:0> << 29);\n            '],{})

    Cvtqlv::Cvtqlv(ExtMachInst machInst)
         : AlphaStaticInst("cvtqlv", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cpys(['  // copy sign\n                Fc_uq = (Fa_uq<63:> << 63) | Fb_uq<62:0>;\n            '],{})

    Cpys::Cpys(ExtMachInst machInst)
         : AlphaStaticInst("cpys", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cpysn([' // copy sign negated\n                Fc_uq = (~Fa_uq<63:> << 63) | Fb_uq<62:0>;\n            '],{})

    Cpysn::Cpysn(ExtMachInst machInst)
         : AlphaStaticInst("cpysn", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::cpyse([' // copy sign and exponent\n                Fc_uq = (Fa_uq<63:52> << 52) | Fb_uq<51:0>;\n            '],{})

    Cpyse::Cpyse(ExtMachInst machInst)
         : AlphaStaticInst("cpyse", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmoveq([' Fc = (Fa == 0) ? Fb : Fc; '],{})

    Fcmoveq::Fcmoveq(ExtMachInst machInst)
         : AlphaStaticInst("fcmoveq", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmovne([' Fc = (Fa != 0) ? Fb : Fc; '],{})

    Fcmovne::Fcmovne(ExtMachInst machInst)
         : AlphaStaticInst("fcmovne", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmovlt([' Fc = (Fa <  0) ? Fb : Fc; '],{})

    Fcmovlt::Fcmovlt(ExtMachInst machInst)
         : AlphaStaticInst("fcmovlt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmovge([' Fc = (Fa >= 0) ? Fb : Fc; '],{})

    Fcmovge::Fcmovge(ExtMachInst machInst)
         : AlphaStaticInst("fcmovge", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmovle([' Fc = (Fa <= 0) ? Fb : Fc; '],{})

    Fcmovle::Fcmovle(ExtMachInst machInst)
         : AlphaStaticInst("fcmovle", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::fcmovgt([' Fc = (Fa >  0) ? Fb : Fc; '],{})

    Fcmovgt::Fcmovgt(ExtMachInst machInst)
         : AlphaStaticInst("fcmovgt", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FB + FP_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FC + FP_Reg_Base;
	_destRegIdx[_numDestRegs++] = FC + FP_Reg_Base;
	_numFPDestRegs++;
	flags[IsFloating] = true;;
    }

// BasicOperateWithNopCheck::mt_fpcr([' FPCR = Fa_uq; ', 'IsIprAccess'],{})

    Mt_fpcr::Mt_fpcr(ExtMachInst machInst)
         : AlphaStaticInst("mt_fpcr", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = MISCREG_FPCR + Misc_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = FA + FP_Reg_Base;
	flags[IsFloating] = true;
	flags[IsIprAccess] = true;;
    }

// BasicOperateWithNopCheck::mf_fpcr([' Fa_uq = FPCR; ', 'IsIprAccess'],{})

    Mf_fpcr::Mf_fpcr(ExtMachInst machInst)
         : AlphaStaticInst("mf_fpcr", machInst, FloatAddOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = FA + FP_Reg_Base;
	_numFPDestRegs++;
	_srcRegIdx[_numSrcRegs++] = MISCREG_FPCR + Misc_Reg_Base;
	flags[IsFloating] = true;
	flags[IsIprAccess] = true;;
    }

// Unknown::unknown(([], {}))

// WarnUnimpl::fetch([],{})

// WarnUnimpl::fetch_m([],{})

// WarnUnimpl::ecb([],{})

// MiscPrefetch::wh64([' EA = Rb & ~ULL(63); ', ' ; '],{'mem_flags': 'PREFETCH'})

    Wh64::Wh64(ExtMachInst machInst)
         : MemoryNoDisp("wh64", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	memAccessFlags = Request::PREFETCH;;
    }

// BasicOperate::rpcc(['\n                /* Rb is a fake dependency so here is a fun way to get\n                 * the parser to understand that.\n                 */\n                uint64_t unused_var M5_VAR_USED = Rb;\n                Ra = FullSystem ? xc->readMiscReg(IPR_CC) : curTick();\n            ', 'IsUnverifiable'],{})

    Rpcc::Rpcc(ExtMachInst machInst)
         : AlphaStaticInst("rpcc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsUnverifiable] = true;;
    }

// BasicOperate::trapb([' ', 'IsSerializing', 'IsSerializeBefore', 'No_OpClass'],{})

    Trapb::Trapb(ExtMachInst machInst)
         : AlphaStaticInst("trapb", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;;
    }

// BasicOperate::excb([' ', 'IsSerializing', 'IsSerializeBefore', 'No_OpClass'],{})

    Excb::Excb(ExtMachInst machInst)
         : AlphaStaticInst("excb", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;;
    }

// BasicOperate::mb([' ', 'IsMemBarrier', 'MemReadOp'],{})

    Mb::Mb(ExtMachInst machInst)
         : AlphaStaticInst("mb", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsMemBarrier] = true;;
    }

// BasicOperate::wmb([' ', 'IsWriteBarrier', 'MemWriteOp'],{})

    Wmb::Wmb(ExtMachInst machInst)
         : AlphaStaticInst("wmb", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsWriteBarrier] = true;;
    }

// FailUnimpl::rc_se(([], {}))

// BasicOperate::rc((['\n                Ra = IntrFlag;\n                IntrFlag = 0;\n            ', 'IsNonSpeculative', 'IsUnverifiable'], {}))

    Rc::Rc(ExtMachInst machInst)
         : AlphaStaticInst("rc", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = MISCREG_INTR + Misc_Reg_Base;
	_destRegIdx[_numDestRegs++] = MISCREG_INTR + Misc_Reg_Base;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsUnverifiable] = true;;
    }

// FailUnimpl::rs_se(([], {}))

// BasicOperate::rs((['\n                Ra = IntrFlag;\n                IntrFlag = 1;\n            ', 'IsNonSpeculative', 'IsUnverifiable'], {}))

    Rs::Rs(ExtMachInst machInst)
         : AlphaStaticInst("rs", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = MISCREG_INTR + Misc_Reg_Base;
	_destRegIdx[_numDestRegs++] = MISCREG_INTR + Misc_Reg_Base;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsUnverifiable] = true;;
    }

// Unknown::unknown(([], {}))

// EmulatedCallPal::halt(['\n                    exitSimLoop("halt instruction encountered");\n                ', 'IsNonSpeculative'],{})

    Halt::Halt(ExtMachInst machInst)
         : EmulatedCallPal("halt", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// EmulatedCallPal::callsys(['\n                    xc->syscall(R0);\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall'],{})

    Callsys::Callsys(ExtMachInst machInst)
         : EmulatedCallPal("callsys", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;
	flags[IsSyscall] = true;;
    }

// EmulatedCallPal::rduniq([' R0 = Runiq; ', 'IsIprAccess'],{})

    Rduniq::Rduniq(ExtMachInst machInst)
         : EmulatedCallPal("rduniq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = 0;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = MISCREG_UNIQ + Misc_Reg_Base;
	flags[IsIprAccess] = true;;
    }

// EmulatedCallPal::wruniq([' Runiq = R16; ', 'IsIprAccess'],{})

    Wruniq::Wruniq(ExtMachInst machInst)
         : EmulatedCallPal("wruniq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = MISCREG_UNIQ + Misc_Reg_Base;
	_srcRegIdx[_numSrcRegs++] = 16;
	flags[IsIprAccess] = true;;
    }

// Unknown::unknown(([], {}))

// CallPal::call_pal((['\n            if (!palValid ||\n                (palPriv\n                 && xc->readMiscReg(IPR_ICM) != mode_kernel)) {\n                // invalid pal function code, or attempt to do privileged\n                // PAL call in non-kernel mode\n                fault = new UnimplementedOpcodeFault;\n            } else {\n                // check to see if simulator wants to do something special\n                // on this PAL call (including maybe suppress it)\n                bool dopal = xc->simPalCheck(palFunc);\n\n                if (dopal) {\n                    xc->setMiscReg(IPR_EXC_ADDR, NPC);\n                    NPC = xc->readMiscReg(IPR_PAL_BASE) + palOffset;\n                }\n            }\n        ', 'IsNonSpeculative'], {}))

    Call_pal::Call_pal(ExtMachInst machInst)
         : CallPalBase("call_pal", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsNonSpeculative] = true;;
    }

// OpcdecFault::hw_st_quad(([], {}))

// HwLoad::hw_ld([' EA = (Rb + disp) & ~3; ', ' Ra = Mem_ul; ', 'L', 'IsSerializing', 'IsSerializeBefore'],{})

    Hw_ldL::Hw_ldL(ExtMachInst machInst)
         : HwLoadStore("hw_ld", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;;
    }

// HwLoad::hw_ld([' EA = (Rb + disp) & ~7; ', ' Ra = Mem_uq; ', 'Q', 'IsSerializing', 'IsSerializeBefore'],{})

    Hw_ldQ::Hw_ldQ(ExtMachInst machInst)
         : HwLoadStore("hw_ld", machInst, MemReadOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	flags[IsMemRef] = true;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// OpcdecFault::hw_st_cond(([], {}))

// HwStore::hw_st([' EA = (Rb + disp) & ~3; ', ' Mem_ul = Ra<31:0>; ', 'L', 'IsSerializing', 'IsSerializeBefore'],{})

    Hw_stL::Hw_stL(ExtMachInst machInst)
         : HwLoadStore("hw_st", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;
	flags[IsStore] = true;;
    }

// HwStore::hw_st([' EA = (Rb + disp) & ~7; ', ' Mem_uq = Ra_uq; ', 'Q', 'IsSerializing', 'IsSerializeBefore'],{})

    Hw_stQ::Hw_stQ(ExtMachInst machInst)
         : HwLoadStore("hw_st", machInst, MemWriteOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RB] : RB;
	flags[IsInteger] = true;
	flags[IsMemRef] = true;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;
	flags[IsStore] = true;;
    }

// Unknown::unknown(([], {}))

// FailUnimpl::hw_st_cond(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// OpcdecFault::hw_mfpr(([], {}))

// HwMoveIPR::hw_mfpr(['\n                int miscRegIndex = (ipr_index < MaxInternalProcRegs) ?\n                        IprToMiscRegIndex[ipr_index] : -1;\n                if(miscRegIndex < 0 || !IprIsReadable(miscRegIndex) ||\n                    miscRegIndex >= NumInternalProcRegs)\n                        fault = new UnimplementedOpcodeFault;\n                else\n                    Ra = xc->readMiscReg(miscRegIndex);\n            ', 'IsIprAccess'],{})

    Hw_mfpr::Hw_mfpr(ExtMachInst machInst)
         : HwMoveIPR("hw_mfpr", machInst, IprAccessOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsIprAccess] = true;;
    }

// Unknown::unknown(([], {}))

// OpcdecFault::hw_mtpr(([], {}))

// HwMoveIPR::hw_mtpr(['\n                int miscRegIndex = (ipr_index < MaxInternalProcRegs) ?\n                        IprToMiscRegIndex[ipr_index] : -1;\n                if(miscRegIndex < 0 || !IprIsWritable(miscRegIndex) ||\n                    miscRegIndex >= NumInternalProcRegs)\n                        fault = new UnimplementedOpcodeFault;\n                else\n                    xc->setMiscReg(miscRegIndex, Ra);\n                if (traceData) { traceData->setData(Ra); }\n            ', 'IsIprAccess'],{})

    Hw_mtpr::Hw_mtpr(ExtMachInst machInst)
         : HwMoveIPR("hw_mtpr", machInst, IprAccessOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = PALMODE ? reg_redir[RA] : RA;
	flags[IsInteger] = true;
	flags[IsIprAccess] = true;;
    }

// Unknown::unknown(([], {}))

// OpcdecFault::hw_rei(([], {}))

// BasicOperate::hw_rei([' xc->hwrei(); ', 'IsSerializing', 'IsSerializeBefore'],{})

    Hw_rei::Hw_rei(ExtMachInst machInst)
         : AlphaStaticInst("hw_rei", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsSerializeBefore] = true;
	flags[IsSerializing] = true;;
    }

// Unknown::unknown(([], {}))

// BasicOperate::arm(['\n                PseudoInst::arm(xc->tcBase());\n            ', 'IsNonSpeculative'],{})

    Arm::Arm(ExtMachInst machInst)
         : AlphaStaticInst("arm", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::quiesce(["\n                // Don't sleep if (unmasked) interrupts are pending\n                Interrupts* interrupts =\n                    xc->tcBase()->getCpuPtr()->getInterruptController();\n                if (interrupts->checkInterrupts(xc->tcBase())) {\n                    PseudoInst::quiesceSkip(xc->tcBase());\n                } else {\n                    PseudoInst::quiesce(xc->tcBase());\n                }\n            ", 'IsNonSpeculative', 'IsQuiesce'],{})

    Quiesce::Quiesce(ExtMachInst machInst)
         : AlphaStaticInst("quiesce", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsQuiesce] = true;;
    }

// BasicOperate::quiesceNs(['\n                PseudoInst::quiesceNs(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsQuiesce'],{})

    QuiesceNs::QuiesceNs(ExtMachInst machInst)
         : AlphaStaticInst("quiesceNs", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	flags[IsNonSpeculative] = true;
	flags[IsQuiesce] = true;;
    }

// BasicOperate::quiesceCycles(['\n                PseudoInst::quiesceCycles(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsQuiesce', 'IsUnverifiable'],{})

    QuiesceCycles::QuiesceCycles(ExtMachInst machInst)
         : AlphaStaticInst("quiesceCycles", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	flags[IsNonSpeculative] = true;
	flags[IsQuiesce] = true;
	flags[IsUnverifiable] = true;;
    }

// BasicOperate::quiesceTime(['\n                R0 = PseudoInst::quiesceTime(xc->tcBase());\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})

    QuiesceTime::QuiesceTime(ExtMachInst machInst)
         : AlphaStaticInst("quiesceTime", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = 0;
	_numIntDestRegs++;
	flags[IsNonSpeculative] = true;
	flags[IsUnverifiable] = true;;
    }

// BasicOperate::rpns(['\n                R0 = PseudoInst::rpns(xc->tcBase());\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})

    Rpns::Rpns(ExtMachInst machInst)
         : AlphaStaticInst("rpns", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = 0;
	_numIntDestRegs++;
	flags[IsNonSpeculative] = true;
	flags[IsUnverifiable] = true;;
    }

// BasicOperate::wakeCPU(['\n                PseudoInst::wakeCPU(xc->tcBase(), R16);\n            ', 'IsNonSpeculative', 'IsUnverifiable'],{})

    WakeCPU::WakeCPU(ExtMachInst machInst)
         : AlphaStaticInst("wakeCPU", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	flags[IsNonSpeculative] = true;
	flags[IsUnverifiable] = true;;
    }

// BasicOperate::deprecated_ivlb(['\n                warn_once("Obsolete M5 ivlb instruction encountered.\\n");\n            '],{})

    Deprecated_ivlb::Deprecated_ivlb(ExtMachInst machInst)
         : AlphaStaticInst("deprecated_ivlb", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;
    }

// BasicOperate::deprecated_ivle(['\n                warn_once("Obsolete M5 ivlb instruction encountered.\\n");\n            '],{})

    Deprecated_ivle::Deprecated_ivle(ExtMachInst machInst)
         : AlphaStaticInst("deprecated_ivle", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;
    }

// BasicOperate::deprecated_exit(['\n                warn_once("deprecated M5 exit instruction encountered.\\n");\n                PseudoInst::m5exit(xc->tcBase(), 0);\n            ', 'No_OpClass', 'IsNonSpeculative'],{})

    Deprecated_exit::Deprecated_exit(ExtMachInst machInst)
         : AlphaStaticInst("deprecated_exit", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5exit(['\n                PseudoInst::m5exit(xc->tcBase(), R16);\n            ', 'No_OpClass', 'IsNonSpeculative'],{})

    M5exit::M5exit(ExtMachInst machInst)
         : AlphaStaticInst("m5exit", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::loadsymbol(['\n                PseudoInst::loadsymbol(xc->tcBase());\n            ', 'No_OpClass', 'IsNonSpeculative'],{})

    Loadsymbol::Loadsymbol(ExtMachInst machInst)
         : AlphaStaticInst("loadsymbol", machInst, No_OpClass)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::initparam(['\n                Ra = PseudoInst::initParam(xc->tcBase());\n            '],{})

    Initparam::Initparam(ExtMachInst machInst)
         : AlphaStaticInst("initparam", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = PALMODE ? reg_redir[RA] : RA;
	_numIntDestRegs++;
	flags[IsInteger] = true;;
    }

// BasicOperate::resetstats(['\n                PseudoInst::resetstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})

    Resetstats::Resetstats(ExtMachInst machInst)
         : AlphaStaticInst("resetstats", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::dumpstats(['\n                PseudoInst::dumpstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})

    Dumpstats::Dumpstats(ExtMachInst machInst)
         : AlphaStaticInst("dumpstats", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::dumpresetstats(['\n                PseudoInst::dumpresetstats(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})

    Dumpresetstats::Dumpresetstats(ExtMachInst machInst)
         : AlphaStaticInst("dumpresetstats", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5checkpoint(['\n                PseudoInst::m5checkpoint(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})

    M5checkpoint::M5checkpoint(ExtMachInst machInst)
         : AlphaStaticInst("m5checkpoint", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5readfile(['\n                R0 = PseudoInst::readfile(xc->tcBase(), R16, R17, R18);\n            ', 'IsNonSpeculative'],{})

    M5readfile::M5readfile(ExtMachInst machInst)
         : AlphaStaticInst("m5readfile", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = 0;
	_numIntDestRegs++;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	_srcRegIdx[_numSrcRegs++] = 18;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5break(['\n                PseudoInst::debugbreak(xc->tcBase());\n            ', 'IsNonSpeculative'],{})

    M5break::M5break(ExtMachInst machInst)
         : AlphaStaticInst("m5break", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5switchcpu(['\n                PseudoInst::switchcpu(xc->tcBase());\n            ', 'IsNonSpeculative'],{})

    M5switchcpu::M5switchcpu(ExtMachInst machInst)
         : AlphaStaticInst("m5switchcpu", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5addsymbol(['\n                PseudoInst::addsymbol(xc->tcBase(), R16, R17);\n            ', 'IsNonSpeculative'],{})

    M5addsymbol::M5addsymbol(ExtMachInst machInst)
         : AlphaStaticInst("m5addsymbol", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_srcRegIdx[_numSrcRegs++] = 16;
	_srcRegIdx[_numSrcRegs++] = 17;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5panic(['\n                panic("M5 panic instruction called at pc = %#x.", PC);\n            ', 'IsNonSpeculative'],{})

    M5panic::M5panic(ExtMachInst machInst)
         : AlphaStaticInst("m5panic", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }
#define  CPANN(lbl) CPA::cpa()->lbl(xc->tcBase())

// BasicOperate::m5a_old(['\n                    panic("Deprecated M5 annotate instruction executed "\n                          "at pc = %#x\\n", PC);\n                ', 'IsNonSpeculative'],{})

    M5a_old::M5a_old(ExtMachInst machInst)
         : AlphaStaticInst("m5a_old", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_bsm(['\n                    CPANN(swSmBegin);\n                ', 'IsNonSpeculative'],{})

    M5a_bsm::M5a_bsm(ExtMachInst machInst)
         : AlphaStaticInst("m5a_bsm", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_esm(['\n                    CPANN(swSmEnd);\n                ', 'IsNonSpeculative'],{})

    M5a_esm::M5a_esm(ExtMachInst machInst)
         : AlphaStaticInst("m5a_esm", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_begin(['\n                    CPANN(swExplictBegin);\n                ', 'IsNonSpeculative'],{})

    M5a_begin::M5a_begin(ExtMachInst machInst)
         : AlphaStaticInst("m5a_begin", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_end(['\n                    CPANN(swEnd);\n                ', 'IsNonSpeculative'],{})

    M5a_end::M5a_end(ExtMachInst machInst)
         : AlphaStaticInst("m5a_end", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_q(['\n                    CPANN(swQ);\n                ', 'IsNonSpeculative'],{})

    M5a_q::M5a_q(ExtMachInst machInst)
         : AlphaStaticInst("m5a_q", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_dq(['\n                    CPANN(swDq);\n                ', 'IsNonSpeculative'],{})

    M5a_dq::M5a_dq(ExtMachInst machInst)
         : AlphaStaticInst("m5a_dq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_wf(['\n                    CPANN(swWf);\n                ', 'IsNonSpeculative'],{})

    M5a_wf::M5a_wf(ExtMachInst machInst)
         : AlphaStaticInst("m5a_wf", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_we(['\n                    CPANN(swWe);\n                ', 'IsNonSpeculative'],{})

    M5a_we::M5a_we(ExtMachInst machInst)
         : AlphaStaticInst("m5a_we", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_sq(['\n                    CPANN(swSq);\n                ', 'IsNonSpeculative'],{})

    M5a_sq::M5a_sq(ExtMachInst machInst)
         : AlphaStaticInst("m5a_sq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_aq(['\n                    CPANN(swAq);\n                ', 'IsNonSpeculative'],{})

    M5a_aq::M5a_aq(ExtMachInst machInst)
         : AlphaStaticInst("m5a_aq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_pq(['\n                    CPANN(swPq);\n                ', 'IsNonSpeculative'],{})

    M5a_pq::M5a_pq(ExtMachInst machInst)
         : AlphaStaticInst("m5a_pq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_l(['\n                    CPANN(swLink);\n                ', 'IsNonSpeculative'],{})

    M5a_l::M5a_l(ExtMachInst machInst)
         : AlphaStaticInst("m5a_l", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_identify(['\n                    CPANN(swIdentify);\n                ', 'IsNonSpeculative'],{})

    M5a_identify::M5a_identify(ExtMachInst machInst)
         : AlphaStaticInst("m5a_identify", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_getid(['\n                    R0 = CPANN(swGetId);\n                ', 'IsNonSpeculative'],{})

    M5a_getid::M5a_getid(ExtMachInst machInst)
         : AlphaStaticInst("m5a_getid", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	_destRegIdx[_numDestRegs++] = 0;
	_numIntDestRegs++;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_scl(['\n                    CPANN(swSyscallLink);\n                ', 'IsNonSpeculative'],{})

    M5a_scl::M5a_scl(ExtMachInst machInst)
         : AlphaStaticInst("m5a_scl", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5a_rq(['\n                    CPANN(swRq);\n                ', 'IsNonSpeculative'],{})

    M5a_rq::M5a_rq(ExtMachInst machInst)
         : AlphaStaticInst("m5a_rq", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// Unknown::unknown(([], {}))
#undef CPANN

// BasicOperate::m5reserved2(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})

    M5reserved2::M5reserved2(ExtMachInst machInst)
         : AlphaStaticInst("m5reserved2", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5reserved3(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})

    M5reserved3::M5reserved3(ExtMachInst machInst)
         : AlphaStaticInst("m5reserved3", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5reserved4(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})

    M5reserved4::M5reserved4(ExtMachInst machInst)
         : AlphaStaticInst("m5reserved4", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// BasicOperate::m5reserved5(['\n                warn("M5 reserved opcode ignored");\n            ', 'IsNonSpeculative'],{})

    M5reserved5::M5reserved5(ExtMachInst machInst)
         : AlphaStaticInst("m5reserved5", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
